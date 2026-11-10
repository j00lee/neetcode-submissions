class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # store the digits of each "section" in temp set
        rowDigits = set()
        colDigits = set()
        
        # each row must contain the digits 1-9 without duplicates
        # each column must contain the digits 1-9 without duplicates
        for i in range(9):
            for j in range(9):
                # check row-wise first
                rowElem = board[i][j]
                if (rowElem in rowDigits and rowElem != "."):
                    print(i)
                    print(j)
                    print(rowDigits)
                    print("rows not valid!")
                    return False
                rowDigits.add(rowElem)
                # now check col-wise
                colElem = board[j][i]
                if (colElem in colDigits and colElem != "."):
                    print("cols not valid!")
                    return False
                colDigits.add(colElem)
            rowDigits = set()
            colDigits = set()

        # each of the nine 3x3 sub-boxes of the grid must contain the 
        # digits 1-9 without duplicates
        boxDigits = set()
        for i in range(9):
            # this is the i-th box
            # figure out the first row and column
            firstRow = (i // 3) * 3
            firstCol = (i % 3) * 3
            print("number box: " + str(i))
            print("firstRow: " + str(firstRow))
            print("firstCol: " + str(firstCol))
            for j in range(3):
                for k in range(3):
                    boxElem = board[firstRow + j][firstCol + k]
                    if (boxElem in boxDigits and boxElem != "."):
                        # print(i)
                        # print(firstRow + j)
                        # print(firstCol + k)
                        # print(boxElem)
                        # print(boxDigits)
                        print("boxes not valid!")
                        return False
                    boxDigits.add(boxElem)
            boxDigits = set()
        return True



