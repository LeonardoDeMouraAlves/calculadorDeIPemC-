#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool validadorDeIP(int xip1, int xip2, int xip3, int xip4, int xmasc){
    
//função para validar se o IP com máscara é valido, todos os IFs representão as regras para um IP com Máscara serem validos, se caso o IP for verdadeiro a função retornara true e se for falso retornara false
    
if(xip1>=256 or xip2>=256  or xip3>=256  or xip4>=256  or xip1<=-1  or xip2<=-1  or xip3<=-1  or xip4<=-1 or xmasc<1 or xmasc>32 or xip1==0 or xip1==127 or xip1 == 255){
    return false;
}

if(xip1!=0 and xip2 == 255 and xip3 == 255 and xip4 == 255){
    return false;
}
if(xip1!=0 and xip2 != 0 and xip3 == 255 and xip4 == 255){
    return false;
}
if(xip1!=0 and xip2 == 0 and xip3 == 0 and xip4 == 0){
    return false;
}
if(xip1!=0 and xip2 != 0 and xip3 == 0 and xip4 == 0){
    return false;
}
if(xip1!=0 and xip2 != 0 and xip3 != 0 and xip4 == 255){
    return false;
}
if(xip1!=0 and xip2 != 0 and xip3 != 0 and xip4 == 0){
    return false;
}

return true;
}

string toBinary(int x){ // Função para converter numeros inteiros para binarios.
    string aux;
    while (x>0){
        aux=((x% 2)==0 ? "0" : "1")+aux;
        x=x/2;
    }
    return aux;
}

char mascCIDRParaInt(int xmasc){
    
//função para converter uma mácara CIDR para decimal 
    
if(xmasc == 32){
    cout<<"255.255.255.255";
}
if(xmasc == 31){
    cout<<"255.255.255.254";
}
if(xmasc == 30){
    cout<<"255.255.255.252";
}
if(xmasc == 29){
    cout<<"255.255.255.248";
}
if(xmasc == 28){
    cout<<"255.255.255.240";
}
if(xmasc == 27){
    cout<<"255.255.255.224";
}
if(xmasc == 26){
    cout<<"255.255.255.192";
}
if(xmasc == 25){
    cout<<"255.255.255.128";
}
if(xmasc == 24){
    cout<<"255.255.255.0";
}
if(xmasc == 23){
    cout<<"255.255.254.0";
}
if(xmasc == 22){
    cout<<"255.255.252.0";
}
if(xmasc == 21){
    cout<<"255.255.248.0";
}
if(xmasc == 20){
    cout<<"255.255.240.0";
}
if(xmasc == 19){
    cout<<"255.255.224.0";
}
if(xmasc == 18){
    cout<<"255.255.192.0";
}
if(xmasc == 17){
    cout<<"255.255.128.0";
}
if(xmasc == 16){
    cout<<"255.255.0.0";
}
if(xmasc == 15){
    cout<<"255.254.0.0";
}
if(xmasc == 14){
    cout<<"255.252.0.0";
}
if(xmasc == 13){
    cout<<"255.248.0.0";
}
if(xmasc == 12){
    cout<<"255.240.0.0";
}
if(xmasc == 11){
    cout<<"255.224.0.0";
}
if(xmasc == 10){
    cout<<"255.192.0.0";
}
if(xmasc == 9){
    cout<<"255.128.0.0";
}
if(xmasc == 8){
    cout<<"255.0.0.0";
}
if(xmasc == 7){
    cout<<"252.0.0.0";
}
if(xmasc == 6){
    cout<<"252.0.0.0";
}
if(xmasc == 5){
    cout<<"248.0.0.0";
}
if(xmasc == 4){
    cout<<"240.0.0.0";
}
if(xmasc == 3){
    cout<<"224.0.0.0";
}
if(xmasc == 2){
    cout<<"192.0.0.0";
}
if(xmasc == 1){
    cout<<"128.0.0.0";
}
if(xmasc == 0){
    cout<<"0.0.0.0";
}

return ' ';
}

char enderecoRede(int xip1, int xip2, int xip3, int xip4, int xmasc){

//função para para calcular endereço de rede, sabemos que o endereço de rede é o primeiro endereço do bloco.

    string aux1;
    int aux = xmasc; 
    
// os IFs determina qual parte da máscara deve ser alterada

    if(aux <= 8 && aux >=0){
    aux1 = toBinary(xip1);
}
    if(aux <= 16 && aux > 8){
    aux1 = toBinary(xip2);
    xmasc = xmasc-8;
}
    if(aux <= 24 &&  aux > 16){
    aux1 = toBinary(xip3);
    xmasc = xmasc-16;
}
    if(aux <= 32 &&  aux > 24){
    aux1 = toBinary(xip4);
    xmasc = xmasc-24;
}

// se caso a máscara não possuir 8bits ela será complementada por 0 no inicio

while(aux1.length() != 8){
    aux1 = '0'+aux1;
}

// alterando o ip host para binario com 8 bits 0 (00000000)
    for(int i = 0; i < 8 ;i++){
        if(i>=xmasc){
            aux1[i]='0';
        }
}

// conversor de vetor char para decimal

    unsigned long dec = 0;
    int i = 0;
    int s;
    s = 8;
    while( s-- ) {
        if( aux1[s] == '0' || aux1[s] == '1' ) {
            dec = dec + pow(2, i++) * (aux1[s] - '0');
        }
    }
    
// impressão do endereço de acordo com a mascara
    
    if(aux <= 8){
    cout<<dec<<".0.0.0";
}
    if(aux <= 16 && aux > 8){
        cout<<xip1<<"."<<dec<<".0.0";
}
    if(aux <= 24 &&  aux > 16){
        cout<<xip1<<"."<<xip2<<"."<<dec<<".0";
}
    if(aux <= 32 &&  aux > 24){
        cout<<xip1<<"."<<xip2<<"."<<xip3<<"."<<dec;
}

return ' ';

}

char enderecoBroadcast(int xip1, int xip2, int xip3, int xip4, int xmasc){

// função para calcular o endereço de broadcast de acordo com o ip e mascara, sabemos que o endereço de broadcast é o utlimo endereço do bloco
    string aux1;
    int aux = xmasc;
    
 // os IFs determina qual parte da máscara deve ser alterada   

    if(aux <= 8 && aux >=0){
    aux1 = toBinary(xip1);
}
    if(aux <= 16 && aux > 8){
    aux1 = toBinary(xip2);
    xmasc = xmasc-8;
}
    if(aux <= 24 &&  aux > 16){
    aux1 = toBinary(xip3);
    xmasc = xmasc-16;
}
    if(aux <= 32 &&  aux > 24){
    aux1 = toBinary(xip4);
    xmasc = xmasc-24;
}

// se caso a máscara não possuir 8bits ela será complementada por 0 no inicio

while(aux1.length() != 8){
    aux1 = '0'+aux1;
}

// alterando o ip host para binario com 8 bits 1 (11111111)
    for(int i = 0; i < 8 ;i++){
        if(i>=xmasc){
            aux1[i]='1';
        }
}
// conversor de vetor char para decimal
    unsigned long dec = 0;
    int i = 0;
    int s;
    s = 8;
    while( s-- ) {
        if( aux1[s] == '0' || aux1[s] == '1' ) {
            dec = dec + pow(2, i++) * (aux1[s] - '0');
        }
    }
    
// impressão do endereço de acordo com a mascara
    
    if(aux <= 8){
    cout<<dec<<".255.255.255";
}
    if(aux <= 16 && aux > 8){
        cout<<xip1<<"."<<dec<<".255.255";
}
    if(aux <= 24 &&  aux > 16){
        cout<<xip1<<"."<<xip2<<"."<<dec<<".255";
}
    if(aux <= 32 &&  aux > 24){
        cout<<xip1<<"."<<xip2<<"."<<xip3<<"."<<dec;
}

return ' ';

}

char enderecoInicialUti(int xip1, int xip2, int xip3, int xip4, int xmasc){
    
    // função para calcular o primeiro endereço utilizavel na rede.

    string aux1, aux2 = toBinary(xip4);
    int aux = xmasc; 
    
    // verificando qual parte do IP será alterada de acordo com o ip e mascara

    if(aux <= 8 && aux >=0){
    aux1 = toBinary(xip1);
}
    if(aux <= 16 && aux > 8){
    aux1 = toBinary(xip2);
    xmasc = xmasc-8;
}
    if(aux <= 24 &&  aux > 16){
    aux1 = toBinary(xip3);
    xmasc = xmasc-16;
}
    if(aux <= 32 &&  aux > 24){
    aux1 = toBinary(xip4);
    xmasc = xmasc-24;
}

// se caso a máscara não possuir 8bits ela será complementada por 0 no inicio

    while(aux1.length() != 8){
    aux1 = '0'+aux1;
}

// alterando o ip host para binario com 8 bits 0 (00000000)
    for(int i = 0; i < 8 ;i++){
        if(i>=xmasc){
            aux1[i]='0';
        }
}

//alterado somente o ultimo bit do bloco

    if(aux <= 32 &&  aux > 24){ // final
        aux1[7]='1';
}
    else{
        while(aux2.length() != 8){
        aux2 = '0'+aux2;
}
    for(int i=0;i<8;i++){
        aux2[i]=0;
    }
     aux2[7]='1';
}

// conversor de vetor char para decimal

    unsigned long dec = 0, dec1 = 0;
    int i = 0;
    int s = 8;
    while( s-- ) {
        if( aux1[s] == '0' || aux1[s] == '1' ) {
            dec = dec + pow(2, i++) * (aux1[s] - '0');
        }
    }
    s = 8;
    i = 0;
    while( s-- ) {
        if( aux2[s] == '0' || aux2[s] == '1' ) {
            dec1 = dec1 + pow(2, i++) * (aux2[s] - '0');
        }
    }
    
    // verificando qual parte do IP será alterada de acordo com o ip e mascara
    
    if(aux <= 8){
    cout<<dec<<".0.0."<<dec1;
}
    if(aux <= 16 && aux > 8){
        cout<<xip1<<"."<<dec<<".0."<<dec1;
}
    if(aux <= 24 &&  aux > 16){
        cout<<xip1<<"."<<xip2<<"."<<dec<<"."<<dec1;
}
    if(aux <= 32 &&  aux > 24){
        cout<<xip1<<"."<<xip2<<"."<<xip3<<"."<<dec;
}

return ' ';

}

char enderecoFinalUti(int xip1, int xip2, int xip3, int xip4, int xmasc){

    // função para calcular o ultimo endereço utilizavel na rede.

    string aux1; 
    int aux = xmasc; 
    
    // verificando qual parte do IP será alterada de acordo com o ip e mascara

    if(aux <= 8 && aux >=0){
    aux1 = toBinary(xip1);
}
    if(aux <= 16 && aux > 8){
    aux1 = toBinary(xip2);
    xmasc = xmasc-8;
}
    if(aux <= 24 &&  aux > 16){
    aux1 = toBinary(xip3);
    xmasc = xmasc-16;
}
    if(aux <= 32 &&  aux > 24){
    aux1 = toBinary(xip4);
    xmasc = xmasc-24;
}

// se caso a máscara não possuir 8bits ela será complementada por 0 no inicio

    while(aux1.length() != 8){
    aux1 = '0'+aux1;
}

// alterando o ip host para binario com 8 bits 1 (11111111)

    for(int i = 0; i < 8 ;i++){
        if(i>=xmasc){
            aux1[i]='1';
        }
}

if(aux>24){
aux1[7]='0';
}
// conversor de vetor char para decimal

    unsigned long dec = 0, dec1 = 0;
    int i = 0;
    int s = 8;
    while( s-- ) {
        if( aux1[s] == '0' || aux1[s] == '1' ) {
            dec = dec + pow(2, i++) * (aux1[s] - '0');
        }
    }
    s = 8;
    i = 0;

    // verificando qual parte do IP será alterada de acordo com o ip e mascara
    
    if(aux <= 8){
    cout<<dec<<".255.255.254";
}
    if(aux <= 16 && aux > 8){
        cout<<xip1<<"."<<dec<<".255.254";
}
    if(aux <= 24 &&  aux > 16){
        cout<<xip1<<"."<<xip2<<"."<<dec<<".254";
}
    if(aux <= 32 &&  aux > 24){
        cout<<xip1<<"."<<xip2<<"."<<xip3<<"."<<dec;
}

return ' ';

}

int conversorCidrParaDecimal(string xmasc){
    
//função para converter CIDR para máscara decimal
    
if(xmasc == "255.255.255.255"){
    return 32;
}
if(xmasc == "255.255.255.254"){
    return 31;
}
if(xmasc == "255.255.255.252"){
    return 30;
}
if(xmasc == "255.255.255.248"){
    return 29;
}
if(xmasc == "255.255.255.240"){
    return 28;
}
if(xmasc == "255.255.255.224"){
    return 27;
}
if(xmasc == "255.255.255.192"){
    return 26;
}
if(xmasc == "255.255.255.128"){
    return 25;
}
if(xmasc == "255.255.255.0"){
    return 24;
}
if(xmasc == "255.255.254.0"){
    return 23;
}
if(xmasc == "255.255.252.0"){
    return 22;
}
if(xmasc == "255.255.248.0"){
    return 21;
}
if(xmasc == "255.255.240.0"){
    return 20;
}
if(xmasc == "255.255.224.0"){
    return 19;
}
if(xmasc == "255.255.192.0"){
    return 18;
}
if(xmasc == "255.255.128.0"){
    return 17;
}
if(xmasc == "255.255.0.0"){
    return 16;
}
if(xmasc == "255.254.0.0"){
    return 15;
}
if(xmasc == "255.252.0.0"){
    return 14;
}
if(xmasc == "255.248.0.0"){
    return 13;
}
if(xmasc == "255.240.0.0"){
    return 12;
}
if(xmasc == "255.224.0.0"){
    return 11;
}
if(xmasc == "255.192.0.0"){
    return 10;
}
if(xmasc == "255.128.0.0"){
    return 9;
}
if(xmasc == "255.0.0.0"){
    return 8;
}
if(xmasc == "254.0.0.0"){
    return 7;
}
if(xmasc == "252.0.0.0"){
    return 6;
}
if(xmasc == "248.0.0.0"){
    return 5;
}
if(xmasc == "240.0.0.0"){
    return 4;
}
if(xmasc == "224.0.0.0"){
    return 3;
}
if(xmasc == "192.0.0.0"){
    return 2;
}
if(xmasc == "128.0.0.0"){
    return 1;
}

return 0;


}

char verificadorDeClasse(int xip1){
    // função para verificar se qual classe o ip pertence
    if(xip1 >= 0 and xip1 <=127){
        return 'A';
    }
    if(xip1 >= 128 and xip1 <=191){
        return 'B';
    }
    if(xip1 >= 192 and xip1 <=223){
        return 'C';
    }
    }

bool exec3(){
    
setlocale(LC_ALL, "Portuguese");

int ip1, ip2, ip3, ip4;
string aux;
int masc;
bool validado = 0;
int continua = 1;

while(continua == 1){

while(validado != 1){

cout<<"Digite um IP válido: (padrão: x.x.x.x)\n";
scanf("%d.%d.%d.%d",&ip1,&ip2,&ip3,&ip4);

cout<<endl<<"Digite a máscara na notação decimal: (padrão x.x.x.x)\n";
cin>>aux;

masc = conversorCidrParaDecimal(aux);

cout<<endl<<endl;



validado = validadorDeIP(ip1, ip2, ip3, ip4, masc);

if(validado != 1){
    cout<<"IP ou máscara esta incorreto"<<endl;
}
}

cout<<"Endereço IP:                         "<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";
cout<<"Máscara decimal:                     "<< mascCIDRParaInt(masc) <<"\n";
cout<<"Máscara CIDR:                        "<<"/"<<masc<<"\n";

if(pow(2,32-masc)-2 <= 0){
cout<<"Número de hosts:                     0\n";
}else{
printf("Número de hosts:                     %0.f\n",pow(2,32-masc)-2);
}

cout<<"Endereço de rede:                    "<<enderecoRede(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço de broadcast:               "<<enderecoBroadcast(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço IP inicial utilizável:      "<<enderecoInicialUti(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço IP final utilizável:        "<<enderecoFinalUti(ip1,ip2,ip3,ip4,masc)<<"\n";

cout<<endl<<"Deseja cacular outro ip? (se sim digite 1, se não digite 0 para voltar ao menu)"<<endl;
cin>>continua;
while(continua <0 or continua>1){
cout<<"Opção não encontrada"<<endl<<"Deseja cacular outro ip? (se sim digite 1, se não digite 0 para voltar ao menu)\n";
cin>>continua;
}
validado=0;
}

return ' ';

}

bool exec2(){
    
cout<<"Calculadora IP (sem classe e com notação CIDR)"<<endl<<endl;
    
setlocale(LC_ALL, "Portuguese");

int ip1, ip2, ip3, ip4;
int masc;
bool validado = 0;
int continua=1;

while(continua == 1){

while(validado != 1){

cout<<"Digite um IP válido: (padrão: x.x.x.x)\n";
scanf("%d.%d.%d.%d",&ip1,&ip2,&ip3,&ip4);

cout<<endl<<"Digite a máscara na notação CIDR: (padrão x)\n";
scanf("%d", &masc);

cout<<endl<<endl;

validado = validadorDeIP(ip1, ip2, ip3, ip4, masc);

if(validado != 1){
    cout<<"IP ou máscara esta incorreto"<<endl;
}
}

cout<<"Endereço IP:                         "<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";
cout<<"Máscara decimal:                     "<< mascCIDRParaInt(masc) <<"\n";
cout<<"Máscara CIDR:                        "<<"/"<<masc<<"\n";

if(pow(2,32-masc)-2 <= 0){
cout<<"Número de hosts:                     0\n";
}else{
printf("Número de hosts:                     %0.f\n",pow(2,32-masc)-2);
}

cout<<"Endereço de rede:                    "<<enderecoRede(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço de broadcast:               "<<enderecoBroadcast(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço IP inicial utilizável:      "<<enderecoInicialUti(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço IP final utilizável:        "<<enderecoFinalUti(ip1,ip2,ip3,ip4,masc)<<"\n";

cout<<endl<<"Deseja cacular outro ip? (se sim digite 1, se não digite 0 para voltar ao menu)"<<endl;
cin>>continua;
while(continua <0 or continua>1){
cout<<"Opção não encontrada"<<endl<<"Deseja cacular outro ip? (se sim digite 1, se não digite 0 para voltar ao menu)\n";
cin>>continua;
}
validado=0;
}
return ' ';

}

bool exec1(){
    
setlocale(LC_ALL, "Portuguese");

cout<<"Calculadora IP (endereçamento com classe)"<<endl<<endl;

int ip1, ip2, ip3, ip4;
bool validado = 0;
int masc=1;
int continua=1;

while(continua == 1){
    
while(validado != 1){

cout<<"Digite um IP válido: (padrão: x.x.x.x)\n";
scanf("%d.%d.%d.%d",&ip1,&ip2,&ip3,&ip4);

if(verificadorDeClasse(ip1) == 'A'){
    masc = 8;
}
if(verificadorDeClasse(ip1) == 'B'){
    masc = 16;
}
if(verificadorDeClasse(ip1) == 'C'){
    masc = 24;
}
if(verificadorDeClasse(ip1) == 'D'){
    masc = 1;
}
if(verificadorDeClasse(ip1) == 'E'){
    masc = 1;
}

cout<<endl<<endl;

validado = validadorDeIP(ip1, ip2, ip3, ip4, masc);

if(validado != 1){
    cout<<"IP ou máscara esta incorreto"<<endl;
}
}
if(ip1>=224 and ip1<=239){
cout<<"Endereço IP:                         "<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";  
cout<<"Classe:                              D\n";
cout<<"Endereço reservado para multicast\n";
}
if(ip1>=240 and ip1<=255){
cout<<"Endereço IP:                         "<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";  
cout<<"Classe:                              E\n";
cout<<"Endereço reservado para uso futuro\n";
}
if(ip1>=0 and ip1<=223){
cout<<"Endereço IP:                         "<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";
cout<<"Classe:                              "<< verificadorDeClasse(ip1)<<"\n";
cout<<"Máscara decimal:                     "<< mascCIDRParaInt(masc) <<"\n";
cout<<"Máscara CIDR:                        "<<"/"<<masc<<"\n";

if(pow(2,32-masc)-2 <= 0){
cout<<"Número de hosts:                     0\n";
}else{
printf("Número de hosts:                     %0.f\n",pow(2,32-masc)-2);
}

cout<<"Endereço de rede:                    "<<enderecoRede(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço de broadcast:               "<<enderecoBroadcast(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço IP inicial utilizável:      "<<enderecoInicialUti(ip1,ip2,ip3,ip4,masc)<<"\n";
cout<<"Endereço IP final utilizável:        "<<enderecoFinalUti(ip1,ip2,ip3,ip4,masc)<<"\n"<<endl;
}

cout<<endl<<"Deseja cacular outro ip? (se sim digite 1, se não digite 0 para voltar ao menu)"<<endl;
cin>>continua;
while(continua <0 or continua>1){
cout<<"Opção não encontrada"<<endl<<"Deseja cacular outro ip? (se sim digite 1, se não digite 0 para voltar ao menu)\n";
cin>>continua;
}
validado=0;
}

return 0;

}

int main(){
    
int i = 1;


while(i!=0){
cout<<"Calculadora IPV4"<<endl<<"Redes de Computadores II"<<endl<<"Aluno: Leonardo de Moura Alves"<<endl<<"Opções: "<<endl<<"1 - Calculadora IP (endereçamento com classe)"<<endl<<"2 - Calculadora IP (sem classe e com notação CIDR)"<<endl<<"3 - Calculadora IP (sem classe e com notação decimal)"<<endl<<endl<<"0 - Pra fechar a calculadora"<<endl<<"Digite o número da opção desejada: ";
cin>>i;

while(i <0 or i>3){
cout<<"Opção não encontrada"<<endl;
cout<<endl<<endl<<"Opções: "<<endl<<"1 - Calculadora IP (endereçamento com classe)"<<endl<<"2 - Calculadora IP (sem classe e com notação CIDR)"<<endl<<"3 - Calculadora IP (sem classe e com notação decimal)"<<endl<<"0 - Pra fechar a calculadora"<<endl<<"Digite o número da opção desejada: ";

cin>>i;
}

cout<<endl;
if(i == 1){
    exec1();
}
if(i == 2){
    exec2();
}
if(i == 3){
    exec3();
}

}

return 0;
}
