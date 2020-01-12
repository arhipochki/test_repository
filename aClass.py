'''
Test module by Alexey Arkhipov
2019-2020
'''

class wideArray(list):
    ''' Extended list class with some sort algorithms '''
    
    def bubbleSort(self):
        ''' Bubble Sort '''

        n = len(self)

        for i in range(n - 1):
            for j in range(n - 1):
                if (self[j] > self[j+1]):
                    self[j], self[j+1] = self[j+1], self[j]


    def createMatrix(self, m, n):
        ''' Creating Matrix '''

        for i in range(0, n):
            self.append([])
            for j in range(0, m):
                self[i].append(0)


    def printMatrix(self):
        ''' Printing matrix like table of nums '''

        s = ""
        for i in range(len(self)):
            for j in range(len(self[i])):
                s += str(self[i][j]) + " "
            print(s + " ")
            s = ""    


    # def quicksort(self):
    #     if len(self) <= 1:
    #         return self
    #     else:
    #         q = choice(self)
    #     l_nums = [n for n in self if n < q]
        
    #     e_nums = [q] * self.count(q)
    #     b_nums = [n for n in self if n > q]
    #     return wideArray.quicksort(l_nums) + e_nums + wideArray.quicksort(b_nums)


def colorText(text, color="white", background="classic"):
    '''This func will return a colored text'''

    # more info - http://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html

    types = {
        "reset": u"\x1b[0m",
        "bold": u"\u001b[1m",
        "underline": u"\u001b[4m",
        "reversed": u"\u001b[7m"
    }

    colors = {
        "red": u"\x1b[31m",
        "green": u"\x1b[32m",
        "yellow": u"\x1b[33m",
        "blue": u"\x1b[34m",
        "magenta": u"\x1b[35m",
        "cyan": u"\x1b[36m",
        "white": u"\u001b[37m",
        #Bright colors
        "bred": u"\x1b[31;1m",
        "bgreen": u"\x1b[32;1m",
        "byellow": u"\x1b[33;1m",        
        "bblue": u"\x1b[34;1m",
        "bmagenta": u"\x1b[35;1m",
        "bcyan": u"\x1b[36;1m",
        "bwhite": u"\u001b[37;1m"
    }

    backgrounds = {
        "classic": "",
        "black": u"\u001b[40m",
        "red": u"\u001b[41m",
        "green": u"\u001b[42m",
        "yellow": u"\u001b[43m",
        "blue": u"\u001b[44m",
        "magenta": u"\u001b[45m",
        "cyan": u"\u001b[46m",
        "white": u"\u001b[47m",
        # Bright colors
        "bblack": u"\u001b[40;1m",
        "bred": u"\u001b[41;1m",
        "bgreen": u"\u001b[42;1m",
        "byellow": u"\u001b[43;1m",
        "bblue": u"\u001b[44;1m",
        "bmagenta": u"\u001b[45;1m",
        "bcyan": u"\u001b[46;1m",
        "bwhite": u"\u001b[47;1m"
    }

    if color.lower() in colors and background.lower() in backgrounds:
        return colors[color.lower()] + backgrounds[background.lower()] + text + types["reset"]
    else:
        if not color.lower() in colors:
            print(colors["red"] + "Unknown color!" + types["reset"])
            return text
        elif not background.lower() in backgrounds:
            print(colors["red"] + "Unknown background!" + types["reset"])
            return text


def fib(n):
    ''' Fibonachi algorithm '''

    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    return (fib(n-1) + fib(n-2))


def getFibPos(num):
    ''' Returning position of Fibonachi num '''

    if num == 0:
        return 0
    else:
        fib1 = 1
        fib2 = 1
        n = 2

        while fib2 < num:
            temp = fib2
            fib2 += fib1
            fib1 = temp
            n += 1
        if fib2 == num:
            return n
        else:
            raise ValueError(str(num) + " isn't a Fib num!")


def bubbleSort(array):
    ''' Bubble Sort for any array '''

    n = len(array)
    for i in range(n - 1):
        for j in range(n - 1):
            if (array[j] > array[j+1]):
                array[j], array[j+1] = array[j+1], array[j]
    
    return array


def quickSort(array):
    ''' Sorting array by quick sort algorithm '''
    
    if array: 
        return quickSort([x for x in array if x < array[0]]) + [x for x in array if x == array[0]] + quickSort([x for x in array if x > array[0]])
    return []


def sumDig(num):
    ''' Counting summary of nums '''
    summary = num % 10
    
    if num >= 10:
        summary += sumDig(num // 10)
    
    return summary


def isPrime(num):
    ''' If num is prime - return True, else - False '''

    k = 2

    while k*k <= num and num % k != 0:
        k += 1
    
    return (k*k > num)


def factorial(num):
    if num == 1:
        return num
    return num * factorial(num - 1)