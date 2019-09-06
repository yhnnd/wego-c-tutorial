    #include <stdio.h>

    void func (int * ptr) {
        *ptr = *ptr + 10;
    }

    int main() {
        int a = 10;
        func(&a);
        printf("%d\n", a);
        return 0;
    }
