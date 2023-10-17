/*Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client‘s telephone number.
Make use of two collision handling techniques and compare them
using number of comparisons required to find a set of telephone
numbers */


#include <iostream>
using namespace std ;
const int MAX = 10 ;
struct phonebook{
  string name ;
  long long int phone ;
};


class myHash{
  public:
    int size, cap ;
    phonebook *arr ;

    myHash(){
      cap = MAX ;
      size = 0 ;
      arr = new phonebook[cap] ;
      for(int i=0; i<cap; i++){
        arr[i].phone = 0 ;
      }
    }

    int Hash(string w){
      int num = w[0] - 97 ;
      return (num % cap) ;
    }

    int insert(phonebook field) ;//structure instance
    int insertQuad(phonebook field) ;
    int search(phonebook field) ;
    int searchQuad(phonebook field) ;
    bool erase(phonebook field) ;
    bool eraseQuad(phonebook field) ;

    void display() ;
};


int myHash :: insert(phonebook field){
  int count = 1 ;
  if(size == cap)
    return -1 ;
  int i = Hash(field.name);
  while(arr[i].name != "" && arr[i].name != "deleted" && arr[i].name != field.name){
    i = (i+1) % cap ;
    count++ ;
  }
  if(arr[i].name == field.name){    // check already exist or not
    return -1 ;
  }
  else{
    arr[i].name = field.name ;
    arr[i].phone = field.phone ;
    size++ ;count++;
    return count ;
  }
}


int myHash :: search(phonebook field){
  int h = Hash(field.name) ;
  int i = h ;
  while(arr[i].name != ""){
    if(arr[i].name == field.name){
      return i ;
    }
    i = (i+1) % cap ;
    if(i == h){
      return -1 ;
    }
  }
  return -1 ;
}


bool myHash :: erase(phonebook field){
  int a = search(field) ;
  if( a > 0){
    size-- ;
    arr[a].name = "deleted" ;
    arr[a].phone = 0 ;
    return true ;
  }
  else{
    cout<<"\nThe key is not present" ;
    return false ;
  }
}


int myHash :: insertQuad(phonebook field){
  int count = 1 ;
  if(size == cap)
    return -1 ;
  int hv = Hash(field.name);
  for(int j=0; j<cap; j++){
    int t = (hv + j*j) % cap ;
    if(arr[t].name == field.name){
      return -1 ;
    }
    else if(arr[t].name == "" || arr[t].name == "deleted"){
      arr[t].name = field.name ;
      arr[t].phone = field.phone ;
      size++ ;
      return count ;
    }
    count++ ;
  }
  return -1 ;
}


int myHash :: searchQuad(phonebook field){
  int h = Hash(field.name) ;
  for(int i=0; i<cap; i++){
    int t = (h + i*i) % cap ;
    if(arr[t].name == field.name){
      return t ;
    }
    else if(arr[t].name == ""){
      return -1 ;
    }
  }
  return -1 ;
}


bool myHash :: eraseQuad(phonebook field){
  int a = searchQuad(field) ;
  if(a > 0){
    size-- ;
    arr[a].name = "deleted" ;
    arr[a].phone = 0 ;
    return true ;
  }
  else{
    cout<<"\nThe key is not present" ;
    return false ;
  }
}


void myHash :: display(){
  for(int i=0; i<cap; i++){
    cout<<arr[i].name<<" , "<<arr[i].phone<<endl ;
  }
}


void linearMenu()
{
  cout<<"\n~~~~ Linear Probing ~~~~" ;
  cout<<"\n1. Insert the phone number " ;
  cout<<"\n2. Delete the phone number " ;
  cout<<"\n3. Search the phone number " ;
  cout<<"\n4. Display the phonebook database " ;
  cout<<"\n5. Exit" ;
  int ch , index , cnt = 0;
  long int num ;
  myHash obj ;
  phonebook field ;
  do{
    cout<<"\nEnter your choice : " ;
    cin>>ch ;
    switch(ch){
      case 1:
      cout<<"\nEnter the name to be inserted " ;
      cin>>field.name ;
      cout<<"\nEnter the phone no. to be inserted " ;
      cin>>field.phone ;
      cnt = obj.insert(field) ;
      if(cnt > 0)
        cout<<"The count is : "<< cnt <<endl;
      break ;
      case 2:
      cout<<"\nEnter the name to be deleted " ;
      cin>>field.name ;
      obj.erase(field) ;
      break ;
      case 3:
      cout<<"\nEnter the name to be searched " ;
      cin>>field.name ;
      index = obj.search(field) ;
      if(index >=0){
        cout<<"\nThe key is found at index "<<index;
      }
      else{
        cout<<"\nKey is no present" ;
      }
      break ;
      case 4:
      obj.display() ;
      break ;
      default:
      cout<<"\nEnter a valid choice" ;
      break ;
    }

  }while(ch!=5);
}





void quadMenu()

{
  cout<<"\n~~~~ Quadratic Probing ~~~~" ;
  cout<<"\n1. Insert the phone number " ;
  cout<<"\n2. Delete the phone number " ;
  cout<<"\n3. Search the phone number " ;
  cout<<"\n4. Display the phonebook database " ;
  cout<<"\n5. Exit" ;
  int ch , index , cnt = 0;
  long int num ;
  myHash obj ;
  phonebook field ;
  while(ch != 5){
    cout<<"\nEnter your choice : " ;
    cin>>ch ;
    switch(ch){
      case 1:
      cout<<"\nEnter the name to be inserted " ;
      cin>>field.name ;
      cout<<"\nEnter the phone no. to be inserted " ;
      cin>>field.phone ;
      cnt = obj.insertQuad(field) ;
      if(cnt > 0){
        cout<<"The count is : "<<cnt<<endl ;
      } ;
      break ;
      case 2:
      cout<<"\nEnter the name to be deleted " ;
      cin>>field.name ;
      obj.eraseQuad(field) ;
      break ;
      case 3:
      cout<<"\nEnter the name to be searched " ;
      cin>>field.name ;
      index = obj.searchQuad(field) ;
      if(index > 0){
        cout<<"\nThe key is found at index "<<index;
      }
      else{
        cout<<"\nKey is not present" ;
      }
      break ;

      case 4:
      obj.display() ;
      break ;
      default:
      cout<<"\nEnter a valid choice" ;
      break ;
    }
  }
}

int main(){
  int opt ;
  cout<<"\n1. Linear probing" ;
  cout<<"\n2. Quadratic probing" ;
  cout<<"\nChoose collision handling method : " ;
  cin>>opt ;
  if(opt == 1){
    linearMenu() ;
  }
  else if(opt == 2){
    quadMenu() ;
  }
  return 0 ;
}
