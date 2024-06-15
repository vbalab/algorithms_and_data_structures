import sys


def rorate(M):
    result = []

    while M:
        result += M.pop(0)
        if M and M[0]:
            for row in M:
                result.append(row.pop())

        if M:
            result += M.pop()[::-1]

        if M and M[0]:
            for row in M[::-1]:
                result.append(row.pop(0))


    return result


if __name__ == "__main__":
    input()
    input_data = sys.stdin.read().strip().split('\n')

    M = [map(int, i.split()) for i in input_data]
    M = [list(i) for i in M]

    result = map(str, rorate(M))

    print(' '.join(result))