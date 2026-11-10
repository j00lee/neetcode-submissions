class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        # Idea: First transpose the matrix
        for i in range(len(matrix)):
            for j in range(i, len(matrix)):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        # Then, reverse each row
        for i in range(len(matrix)):
            matrix[i] = matrix[i][::-1]
