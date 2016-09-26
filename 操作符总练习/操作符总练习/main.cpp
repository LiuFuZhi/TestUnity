
#include <iostream>
#include <stdlib.h>
using namespace std;
//llike
//statement
class MyString{
public:
    //1、默认构造函数
    MyString() {
        this->str = new char[7];
        strcpy(this->str, "unknow");
    }
    
    //2、有一个参数的构造函数
    MyString(char *_name) {
        this->str = new char[strlen(_name)+1];
        strcpy(this->str, _name);
    }
    
    //3、析构函数
    ~MyString() {
        if (this->str != NULL) {
            delete [] this->str;
            this->str = NULL;
        }
    }
    
    //4、<<运算符重载
    friend ostream& operator<<(ostream& out,const MyString &s) {
        out<<s.str<<endl;
        return out;
    }
    
    //5、＋运算符重载
    MyString operator+(const MyString &s1) {
        unsigned long length1 = strlen(this->str);
        unsigned long length2 = strlen(s1.str);
        const int length = (int)length1 + (int)length2 ;
        char array[length];
        
        for (int i=0; i<length1; ++i) {
            array[i] = this->str[i];
        }
        int k = 0;
        for (int m=(int)length1; m<length; ++m) {
            array[m] = s1.str[k++];
        }
        
        return MyString(array);
    }
    
    //6、＋＝运算符重载
    MyString& operator+=(const MyString &s1) {
        unsigned long length1 = strlen(this->str);
        unsigned long length2 = strlen(s1.str);
        const int length = (int)length1 + (int)length2 ;
        char array[length];
        
        for (int i=0; i<length1; ++i) {
            array[i] = this->str[i];
        }
        int k = 0;
        for (int m=(int)length1; m<length; ++m) {
            array[m] = s1.str[k++];
        }
        
        delete [] this->str;
        this->str = new char[length+1];
        strcpy(this->str, array);
        
        return *this;
    }
    
    //7、＝＝运算符重载
    bool operator==(const MyString &s1) {
        char *str1 = this->str;
        char *str2 = s1.str;
        bool result = true;
        
        while (*str1 != '\0' && *str2 != '\0') {
            if (*str1!= *str2) {
                str1++;
                str2++;
            } else {
                result = false;
                break;
            }
        }
        if (*str1 == '\0' && *str2 == '\0') {
            result = false;
        } else {
            result = true;
        }
        
        return result;
    }
    
    //8、＝ 运算符重载
    MyString& operator=(const MyString &s1) {
        if (this != &s1) {
            delete [] this->str;
            this->str = new char[strlen(s1.str)+1];
            strcpy(this->str, s1.str);
        }
        return *this;
    }
    
    //9、[] 运算符重载 (两个)
    const char& operator[](int index)const {
        return this->str[index];
    }
    char& operator[](int index) {
        return this->str[index];
    }
    //10、const char& at(int index)const;
    const char& at(int index)const {
        return this->str[index];
    }
    //11、char& at(int index)；
    char& at(int index) {
        return this->str[index];
    }
    //12、> 运算符重载
    bool operator>(const MyString &s1) {
        char *str1 = this->str;
        char *str2 = s1.str;
        bool result =false;
        
        while (*str1 != '\0' && *str2 != '\0') {
            if (*str1 <= *str2) {
                str1++;
                str2++;
            } else {
                result = true;
                break;
            }
        }
        if (*str1 == '\0' && *str2 == '\0') {
            result = false;
        }
        return result;
    }
    
private:
    char *str;
};

int main(int argc, const char * argv[]) {
    
    MyString s1((char*)"aad");
    MyString s2((char*)"bba");
    cout<<(s1>s2)<<endl;
    cout<<(s1+s2);
    return 0;
}
//自己做的题目，有用的。
class Vector{
    friend istream& operator >>(istream& in,Vector& v);
    friend ostream& operator <<(ostream& out,const Vector& v);
private:
    int str;
    char* str1;
public:
    Vector(){
        this->str=0;
        this->str1=new char[6];
        strcpy(this->str1, "balla");
    }
    Vector(int str,char*str1){
        this->str=str;
        this->str1=new char[strlen(str1)+1];
        strcpy(this->str1, str1);
    }
    Vector(Vector& v){
        this->str=v.str;
        this->str1=new char[strlen(v.str1)+1];
        strcpy(this->str1, v.str1);
    }
    ~Vector(){
        if (this->str1!=NULL) {
            delete [] this->str1;
            this->str1=NULL;
        }
    }
    Vector& operator=(Vector& v){
        
        delete [] this->str1;
        this->str1=NULL;
        this->str1=new char[strlen(v.str1)+1];
        strcpy(this->str1, v.str1);
        this->str=v.str;
        return *this;
        
    }
    char& operator[](int index){
        return str1[index];
    }
    Vector operator+(Vector& v){
        strcat(this->str1, v.str1);
        unsigned long length=strlen(this->str1)+1;
        char array[length];
        strcpy(array,this->str1);
        int a=this->str+v.str;
        Vector v2(a,array);
        return v2;
    }
    bool operator==(Vector& v){
        bool result=true;
        char *str2=this->str1;
        char *str3=v.str1;
        if ((this->str)==v.str) {
            
            
            while(*str2!='\0'&&*str3!='\0'){
                if ((this->str1)==v.str1) {
                    str2++;
                    str3++;
                }
                else{
                    result=false;
                    break;
                    
                }
            }
            if ((*str2='\0')||(*str3='\0')) {
                result=false;
            }
            else{result=true;}
        }
        else {result=false;}
        return result;
        
    }
};
istream& operator >>(istream& in,Vector& v){
    in>>v.str;
    in>>v.str1;
    return in;
}
ostream& operator <<(ostream& out,const Vector& v){
    out<<"str="<<v.str<<","<<"str1="<<v.str1<<endl;
    return out;
}




//int main(){
//    Person e;
//    e.print();
//    Person e1("make",22,"boy");
//    e1.print();
//    Doctor p;
//    p.print();
//    Doctor p1("make",22,"boy",4,"alibaba");
//    p1.print();
//    Doctor1 d("make",22,"boy",4,"alibaba");
//    Vehicle t("java","china","1101",2,40.0,500.5);
//    t.print();
//    Truck t1("java","china","1101",2,40.0,500.5,"to korea",1000);
//    t1.print();
//    Car c("java","china","1101",2,40.0,500.5,"to korea",1000,10);
//    c.print();
//   }

//    Cylinder c(1,2,3,4);
//    c.print();
//int main(){
//    Vector v(4,"bala");
//    Vector v1(6,"kala");
//    //Vector v3;
//    //cin>>v3;
//    // cin>>v1;
//    
//    cout<<v;
//    cout<<v1;
//    Vector v4(v);
//    cout<<v4<<endl;
//    v=v1;
//    cout<<v;
//    cout<<v1;
//    
//    
//    //cout<<v3;
//    v[2]='k';
//    //cout<<v;
//    cout<<(v+v1);
//    cout<<(v==v1)<<endl;
//    
//    
//}
