from monteCarlo import *


bags = discreteInput("bags", [1, 2, 3, 4])
apples = discreteInput("apples", [0, 10, 20, 30], [0.2, 0.25, 0.75, 1])
nabananers = normalDistInput("nabanana", 3, 1)


def fitting(inputs):
    return inputs[0] + 10*inputs[1]


someFunc = OutputFunction("fitting", fitting)
judge = OutputFunction("judge", lambda x: fitting(x) > 300)

testSimul = Simul(series=[bags, apples, nabananers],
                  functions=[someFunc, judge])
testSimul.run(10000)
print(testSimul)

# anal = testSimul.shareof("judge", [True, False])
# print(anal)

# df = testSimul.getdf()
# s = str(df)
# print(s)
