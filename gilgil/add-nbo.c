#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>


uint32_t read_file(char* filename){
    uint32_t number = 0;

    FILE* file = fopen(filename, "rb");
    if (file == NULL){
       printf("NO OPEN FILE");
       exit(1);
    }

    fread(&number, sizeof(uint32_t),1,file);
    fclose(file);
    number = ntohl(number);

    return number;
}

int main(){
    char file1[] = "num(704).bin";
    char file2[] = "num(448).bin";

    uint32_t number_a = read_file(file1);
    uint32_t number_b = read_file(file2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", number_a,number_a,number_b,number_b,number_a + number_b,number_a + number_b);
}
