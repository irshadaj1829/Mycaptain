#include <iostream>
int main(){

	using namespace std;

	int n[5];
  	int i,j;
  	cout << "Enter elements ";

	 for ( i = 0; i<5; i++ )
	 {
	 	
    	        cin >>  n[i];
  	}

  	cout<<"you entered  ";
  	for (j = 0; j < 5; j++ )
  	{
    	       cout<< n[j] << endl;
  	}

	return 0;
}
