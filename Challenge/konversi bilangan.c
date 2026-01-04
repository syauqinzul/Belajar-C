#include <stdio.h>
#include <math.h>

void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;
    
    if(decimal == 0) {
        printf("0");
        return;
    }
    
    while(decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    printf("Binary: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int binaryToDecimal(long long binary) {
    int decimal = 0, i = 0, remainder;
    
    while(binary != 0) {
        remainder = binary % 10;
        binary = binary / 10;
        decimal += remainder * pow(2, i);
        i++;
    }
    
    return decimal;
}

void decimalToHexadecimal(int decimal) {
    char hex[100];
    int i = 0, remainder;
    
    if(decimal == 0) {
        printf("0");
        return;
    }
    
    while(decimal != 0) {
        remainder = decimal % 16;
        
        if(remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A';
        }
        
        decimal = decimal / 16;
        i++;
    }
    
    printf("Hexadecimal: 0x");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

int main() {
    int choice, decimal;
    long long binary;
    
    do {
        printf("\n=== KONVERSI BILANGAN ===\n");
        printf("1. Decimal ke Binary\n");
        printf("2. Binary ke Decimal\n");
        printf("3. Decimal ke Hexadecimal\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Masukkan bilangan decimal: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
                
            case 2:
                printf("Masukkan bilangan binary: ");
                scanf("%lld", &binary);
                printf("Decimal: %d\n", binaryToDecimal(binary));
                break;
                
            case 3:
                printf("Masukkan bilangan decimal: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;
                
            case 4:
                printf("Terima kasih!\n");
                break;
                
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(choice != 4);
    
    return 0;
}