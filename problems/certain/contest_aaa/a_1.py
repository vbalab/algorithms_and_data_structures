import sys


def rotate_matrix(matrix):
    m = len(matrix)

    rotated_matrix = [[0] * m for _ in range(m)]

    for i in range(m):
        for j in range(m):
            rotated_matrix[j][m - i - 1] = matrix[i][j]


    return rotated_matrix


if __name__ == "__main__":
    input_data = sys.stdin.read().strip().split('\n')

    matrix = [map(int, i.split()) for i in input_data]
    matrix = [list(i) for i in matrix]


    rotated_matrix = rotate_matrix(matrix)


    for row in rotated_matrix:
        print(' '.join(map(str, row)))
