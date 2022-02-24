import pandas as pd
import numpy as np
import random


class inputFunction:
    def __init__(self, name, function):
        self.name = name
        self.samples = []
        self.function = function
        random.seed()
        self.n = 0

    def __iter__(self):
        self.n = 0
        return self

    def __next__(self):
        if self.n < len(self.samples):
            ans = self.samples[self.n]
            self.n += 1
            return ans
        else:
            raise StopIteration

    def __str__(self):
        ans = self.name + "\n"
        for elem in self:
            ans = ans + str(elem) + "\n"
        return ans

    def sample(self, samples=1):
        self.samples = [self.function(random.uniform(0, 1))
                        for elem in range(samples)]
        return self.samples


class discreteInput (inputFunction):

    def __init__(self, name, values, probs=[]):
        self.name = name
        self.values = values
        self.len = len(values)
        self.samples = []
        random.seed()

        if probs == []:
            self.probs = []
            for i in range(self.len):
                self.probs.append((i+1) * 1/self.len)
        else:
            self.probs = probs

        if len(self.values) != len(self.probs):
            print("Values and probabilities do not have same shape")
            raise ValueError

    def sample(self, samples=1):
        self.samples = random.choices(
            self.values, cum_weights=self.probs, k=samples)
        return self.samples


class normalDistInput (inputFunction):

    def __init__(self, name, mean, stdDev):
        self.name = name
        self.mean = mean
        self.stdDev = stdDev
        self.samples = []
        self.function = lambda x: random.gauss(mean, stdDev)
        random.seed()


class OutputFunction:
    def __init__(self, name, funct):
        self.name = name
        self.funct = funct

    def compute(self, inputs):
        return self.funct(inputs)

    def __str__(self):
        return self.name


class Simul:
    def __init__(self, series=[], functions=[]):
        self.series = series
        self.functions = functions
        self.labels = [s.name for s in self.series] + \
            [f.name for f in self.functions]
        self.result = []
        self.df = []

    def __str__(self):
        self.getdf()
        return str(self.df)

    def addInputVal(self, inputValue):
        self.series.append(inputValue)
        self.labels = [s.name for s in self.series] + \
            [f.name for f in self.functions]

    def addOutputFunction(self, outputFunction):
        self.series.append(outputFunction)
        self.labels = [s.name for s in self.series] + \
            [f.name for f in self.functions]

    def run(self, iters):
        inputData = [s.sample(iters) for s in self.series]
        inputDataTransposed = [list(t) for t in list(zip(*inputData))]

        outputData = [[func.compute(row) for row in inputDataTransposed]
                      for func in self.functions]
        # for func in self.functions:
        #   output = [ func.compute(row) for row in inputData]
        #   outputData.append(output)

        self.result = inputData + outputData
        return self.result

    def getdf(self):
        self.df = pd.DataFrame(
            data=list(zip(*self.result)), columns=self.labels)
        return self.df

    def shareof(self, label, values):
        ans = []
        self.getdf()
        s = self.getComponent(label)
        if isinstance(label, str) == False:
            return None
        for v in values:
            filter = (self.df[label] == v)
            filteredDf = self.df.loc[filter]
            for col in self.labels:
                s = filteredDf.value_counts(col, sort=False)
                # print(s)
                s["total"] = s.sum()
                s.to_frame(name=col)
                s["percent"] = s[col]/s["total"]
                # print(s)
                # print(total)

                # s["percent"] = s.map(lambda x: x/total)
                # print(s)
                ans.append(s)
        return ans

    def getComponent(self, label):
        for s in self.series:
            if s.name == label:
                return s
        for f in self.functions:
            if f.name == label:
                return f

        print("getComponent label not found")
        raise ValueError
        return None
