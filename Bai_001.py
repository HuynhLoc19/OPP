
def SUM(n):
    if n==0:
        return 0
    S = SUM(n-1)
    return(S+n)

n = int(input('Nhập n: '))
print('Tổng dãy số [1:{}]: '.format(n), SUM(n))