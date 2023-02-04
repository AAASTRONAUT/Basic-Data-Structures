#include <iostream>

using namespace std;

template <class T>
class Array{
public:
    T *A;
    int length;
    int size;
    void swap(int *a , int *b);
    
    Array(){
        length = 1;
        A = new T[size];
    }
    Array(int len){
        length = len;
        A = new T[size];
    }
    ~Array(){
        delete []A;
    }
    
    void display(){
        for (int i=0 ; i<length ; i++){
            cout<<A[i]<<"\t";
        }
        cout<<endl;
    }
    void insert(int index , T n);
    T sum();
    T single_missing();
    void multiple_missing();
    void hash();
    void find_duplicate();
    void find_duplicate_unsorted();
    T *minMax();
};

template <class T>
void Array<T>::insert(int index , T n){
    if((index<=length) && (index >= 0)){
        A[index] = n;
        length++;
    }
    else cout<<"Invalid Index"<<"\n";
}

template <class T>
T Array<T>::sum(){
    static int i = -1;
    if(i<=length){
        i++;
        return A[i] + sum();
    }
    else return 0;
}

template <class T>
T Array<T>::single_missing(){
    int diff = A[0];
    for (int i =0; i<length ; i++ ){
        if(diff != A[i]-i) return i+diff;
        else continue;
    }
    return NULL;
}

template <class T>
void Array<T>::multiple_missing(){
    int diff=A[0];
    for (int i=0 ; i<length ; i++){
        if(diff != A[i]-i){
            while(diff<A[i]-i){
                cout<<i+diff<<endl;
                diff++;
            }
        }
        else continue;
    }
}

template <class T>
void Array<T>::hash(){
    T l = minMax()[0], h = minMax()[1];
    Array<int> H(h-l+1);
    for(int i=0 ; i<length ; i++){
        H.A[A[i]-l]+=1;
    }
    for (int i=0 ; i<H.length ; i++){
        if(H.A[i]==0) cout<<i+l<<endl;
        else continue;
    }
}
 
template <class T>
void Array<T>::find_duplicate(){
    T last_duplicate = 0;
    int count = 1;
    for(int i=0 ; i<length ; i++){
        if(A[i] == A[i+1]){
            count++;
            if(A[i] == last_duplicate) continue;
            else {
                last_duplicate = A[i];
                cout<<last_duplicate<<", ";
            }
        }
        else {
            cout<<"count:"<<count<<endl;
            count=1;
        }
    }
}

template <class T>
void Array<T>::find_duplicate_unsorted(){
    Array<int> dup(length);
    for(int i=0 ; i<length ; i++){
        dup.A[i] = A[i];
    }
    for(int i =0 ; i<length ; i++){
        int count = 1;
        for (int j=i+1 ; j<length ; j++){
            if((dup.A[i] == dup.A[j]) && (dup.A[i]!= -1)){
                dup.A[j] = -1;
                count++;
            }
            else{
                continue;
            }
        }
        if(count>1){
            cout<<A[i]<<", "<<"count:"<<count<<endl;
        }
    }
}

template <class T>
T *Array<T>::minMax(){
    int min = A[0] , max = A[0];
    for (int i =0 ; i<length ; i++){
        if(A[i]>max) max = A[i];
        else if(A[i]<min) min = A[i];
        else continue;
    }
    T arr[2] = {min,max};
    return arr;
}

int main() {
    cout<<"enter the length of array:";
    int len;
    cin>>len;
    Array<int> ar(len);
    ar.size = ar.length*sizeof(int);
    
    //initializing the array
    cout<<"enter the elements of array:\n";
    for (int i=0 ; i<ar.length ; i++){
        cin>>ar.A[i];
    }
    
    int choice=2;
    while(choice<10){
        cout<<"Choose an operation:"<<endl;
        cout<<"1. insert"<<endl;
        cout<<"2. Display array"<<endl;
        cout<<"3. sum"<<endl;
        cout<<"4. find missing element"<<endl;
        cout<<"5. find multiple missing elements"<<endl;
        cout<<"6. find missing in unsorted array"<<endl;
        cout<<"7. find duplicates in array"<<endl;
        cout<<"8. find duplicates in a unsorted array"<<endl;
        cout<<"9. find minimumm and maximum"<<endl;
        cout<<"10. Exit"<<endl<<":";
        cin>>choice;
        switch(choice){
            case 1:
                int index, element;
                cout<<"Enter element to be inserted:"; cin>>element;
                cout<<"Enter index:"; cin>>index;
                ar.insert(index , element);
                break;
            case 2:
                ar.display();
                break;
            case 3:
                cout<<ar.sum()<<endl;
                break;
            case 4:
                cout<<ar.single_missing()<<endl;
                break;
            case 5:
                ar.multiple_missing();
                break;
            case 6:
                ar.hash();
                break;
            case 7:
                ar.find_duplicate();
                break;
            case 8:
                ar.find_duplicate_unsorted();
                break;
            case 9:
                cout<<ar.minMax()[0]<<endl<<ar.minMax()[1]<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
