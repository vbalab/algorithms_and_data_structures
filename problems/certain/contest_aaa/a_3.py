import sys


def calculate(games):
    n = len(games)


    total = [0, 0, 0]
    for game in games:
        if game[0] == game[2]:
            total[1] += 1
        else:
            if game[0] == 'R' and game[2] == 'S':
                total[0] += 1
            elif game[0] == 'S' and game[2] == 'P':
                total[0] += 1
            elif game[0] == 'P' and game[2] == 'R':
                total[0] += 1
            else:
                total[2] += 1


    total = [(i / n) * 100 for i in total]
    if total[0] > total[2]:
        print("Настя")
        print(f"W: {total[0]:.2f}%\nD: {total[1]:.2f}%\nL: {total[2]:.2f}%\n")
    elif total[2] > total[0]:
        print("Ксюша")
        print(f"W: {total[2]:.2f}%\nD: {total[1]:.2f}%\nL: {total[0]:.2f}%\n")
    else:
        print("Ничья")
        print(f"W: {total[0]:.2f}%\nD: {total[1]:.2f}%\nL: {total[2]:.2f}%\n")


if __name__ == "__main__":
    input_data = sys.stdin.read().strip().split('\n')

    calculate(input_data)
