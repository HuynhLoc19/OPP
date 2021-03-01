def DaySo(n):
    if n==0:
        return 0
    S = DaySo(n-1)
    return S+n**2

n = int(input('Nhập n: '))
print('Tổng bình phương dãy số là: ', DaySo(n))