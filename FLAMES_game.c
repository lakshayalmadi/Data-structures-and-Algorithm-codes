#include <stdio.h> 
#include <string.h> 
  

void flame(char* a, char* b) 
{ 
    int i, j, k, l = 1, n, m, sc = 0, tc, rc = 0, fc = 5; 
    char q[25], w[25], c; 
    char f[] = "flames"; 
    strcpy(q, a); 
    strcpy(w, b); 
    n = strlen(a); 
    m = strlen(b); 
    tc = n + m; 
   for (i = 0; i < n; i++) { 
        c = a[i]; 
        for (j = 0; j < m; j++) { 
            if (c == b[j]) { 
                a[i] = -1; 
                b[j] = -1; 
                sc = sc + 2; 
                break; 
            } 
        } 
    } 
   rc = tc - sc; 
    for (i = 0;; i++) { 
        if (l == (rc)) { 
            for (k = i; f[k] != '\0'; k++) { 
                f[k] = f[k + 1]; 
            } 
            f[k + 1] = '\0'; 
            fc = fc - 1; 
            i = i - 1; 
            l = 0; 
        } 
        if (i == fc) { 
            i = -1; 
        } 
        if (fc == 0) { 
            break; 
        } 
        l++; 
    } 
   if (f[0] == 'e') 
        printf("%s is ENEMY to %s ", q, w); 
    else if (f[0] == 'f') 
        printf("%s is FRIEND to %s ", q, w); 
    else if (f[0] == 'm') 
        printf("%s is going to MARRY %s", q, w); 
    else if (f[0] == 'l') 
        printf("%s is in LOVE with %s ", q, w); 
    else if (f[0] == 'a') 
        printf("%s has more AFFECTION on %s ", q, w); 
    else
        printf("%s and %s are SISTERS/BROTHERS ", q, w); 
} 
int main() 
{   
    char a[] = "AJAY"; 
    char b[] = "PRIYA"; 
    flame(a, b); 
}
