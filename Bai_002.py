
# Tính n!

def Giai_Thua(n):
    if n==0:
        return 1
    T = Giai_Thua(n-1)
    return T*n

n = int(input('Nhập n: '))
print('{0}!='.format(n),Giai_Thua(n))