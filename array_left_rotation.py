def array_left_rotation(a, n, k):
    while(k>=n):
        k=k%n
    b=a
    a=a[k:]
    a.extend(b[0:k])
    return a
