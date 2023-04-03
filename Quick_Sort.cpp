#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>

using namespace std;
class Node{
	public:
	    string InvN, STCODE, desT, quanT, invD, unitP, cusId, cntry;
};
//split function to split the date
int comp = 0;
int swaps = 0;
// for compare the date
bool isSmaller(string d1, string d2){
	string dd1;
    string mm1;
    string yy1;
    string dd2;
    string mm2;
    string yy2;
	if(d1.size() == 10){
		    dd1 = d1.substr(0,2);
		    mm1 = d1.substr(3,2);
		    yy1 = d1.substr(6,4);
    }
    if(d2.size() == 10){
		    dd2 = d2.substr(0,2);
		    mm2 = d2.substr(3,2);
		    yy2 = d2.substr(6,4);
    }
    if(yy1 < yy2){
		    return true;
	    }
    else if(yy1 == yy2){
		if(mm1 < mm2){
			return true;
		}
		else if(mm1 == mm2){
			if(dd1 < dd2){
				return true;
			}
		}
	}
	return false;
}

int partitionDates(vector<Node> &A, int s, int e, int x){

	srand(time(NULL));
    int random = s + rand() % (s - e);

    swap(A[random], A[s]);

    int i = s-1, j = e+1;

    string pivot = A[s].invD;

    while(true){

        do{
        	i++;
		}while((isSmaller((A[i].invD), pivot)));

        do{
        	j--;
		}while((isSmaller(pivot, A[j].invD)));

        if (i >= j)
            return j;

        swap(A[i], A[j]);
        swaps++;
    }
}

void quickSortD(vector<Node> &A, int s, int e,int x){
	if(s < e){
		int p = partitionDates(A, s, e, x);

		comp++;
		quickSortD(A, s, p, x);
		quickSortD(A, p+1, e, x);
	}
}

int partition(vector<Node> &A, int s, int e, int x){

	srand(time(NULL));
    int random = s + rand() % (s - e);

    swap(A[random], A[s]);

    int i = s-1, j = e+1;

    while(true){

    	if(x == 1){
    		string pivot = A[s].InvN;
//            Move i till find element greater then pivot
            do{
            	i++;
			}while(A[i].InvN < pivot);

//            move j till element lesser than pivot
            do{
            	j--;
			}while(A[j].InvN > pivot);


            if (i >= j)
                return j;
//            if both loops break then swap
            swap(A[i], A[j]);
            swaps++;
        }
        if(x == 2){
        	string pivot = A[s].desT;
//            Move i till find element greater then pivot
            do{
            	i++;
			}while(A[i].desT < pivot);

//            move j till element lesser than pivot
            do{
            	j--;
			}while(A[j].desT > pivot);


            if (i >= j)
                return j;
//            if both loops break then swap
            swap(A[i], A[j]);
            swaps++;
        }
        if(x == 3){
        	string pivot = A[s].quanT;
//            Move i till find element greater then pivot
            do{
            	i++;
			}while(A[i].quanT < pivot);

//            move j till element lesser than pivot
            do{
            	j--;
			}while(A[j].quanT > pivot);


            if (i >= j)
                return j;
//            if both loops break then swap
            swap(A[i], A[j]);
            swaps++;
        }
        if(x == 4){
        	string pivot = A[s].unitP;
//            Move i till find element greater then pivot
            do{
            	i++;
			}while(A[i].unitP < pivot);

//            move j till element lesser than pivot
            do{
            	j--;
			}while(A[j].unitP > pivot);


            if (i >= j)
                return j;
//            if both loops break then swap
            swap(A[i], A[j]);
            swaps++;
        }
        if(x == 5){
        	string pivot = A[s].cusId;
//            Move i till find element greater then pivot
            do{
            	i++;
			}while(A[i].cusId < pivot);

//            move j till element lesser than pivot
            do{
            	j--;
			}while(A[j].cusId > pivot);


            if (i >= j)
                return j;
//            if both loops break then swap
            swap(A[i], A[j]);
            swaps++;
        }
        if(x == 6){
        string pivot = A[s].cntry;
//            Move i till find element greater then pivot
            do{
            	i++;
			}while(A[i].cntry < pivot);

//            move j till element lesser than pivot
            do{
            	j--;
			}while(A[j].cntry > pivot);


            if (i >= j)
                return j;
//            if both loops break then swap
            swap(A[i], A[j]);
            swaps++;
        }
}
}

void quickSort(vector<Node> &A, int s, int e,int x){
	if(s < e){
		int p = partition(A, s, e, x);

		comp++;
		quickSort(A, s, p, x);
		quickSort(A, p+1, e, x);
	}
}

int main() {
	//create a file to store the data
	fstream fout;

	//reading a file
	ifstream csv_file("A2.1_ecommerce - A2.1_ecommerce - 1.csv");

	fout.open("A2.commerce2.1.b.csv", ios::out);

	fout << "Invoice Id " << ", " << "Stock Code " << ", " << "Description " << ", " << "Quantity " << ", " << "Invoice Date " << ", " << "Unit Price " << ", " << "Customer ID" << ", " << "Country " <<'\n';

	if (!csv_file) {
		cout << "File not created!";
	}
	else {
		vector<Node> data(151);

        string row_data, word;
        int col = 0,l = 0;
        int firstLine = 0;

        while(getline(csv_file, row_data))
        {
        if(firstLine != 0){
            stringstream s(row_data);
            int col = 0;
		    while(getline(s, word, ',')){
		    	if(col == 0){
		    		data[l].InvN = word;
				}
				else if(col == 3){
					data[l].quanT = word;
				}
				else if(col == 1){
					data[l].STCODE = word;
				}
				else if(col == 2){
					data[l].desT = word;
				}
				else if(col == 4){
					data[l].invD = word;
				}
				else if(col == 7){
					data[l].cntry = word;
				}
				else if(col == 5){
					data[l].unitP = word;
				}
				else if(col == 6){
					data[l].cusId = word;
				}
				col++;
			}
			l++;
        }
        firstLine++;
    }

         cout << "Choose an option..." << endl;
    	 cout << '\n';
    	 cout << " 1 : Sort By Invoice" << endl;
    	 cout << '\n';
	     cout << " 2 : Sort By Description" << endl;
	     cout << '\n';
	     cout << " 3 : Sort By Quantity" << endl;
	     cout << '\n';
	     cout << " 4 : Sort By UnitPrice" << endl;
	     cout << '\n';
	     cout << " 5 : Sort By CustomerID" << endl;
	     cout << '\n';
	     cout << " 6 : Sort By Country" << endl;
	     cout << '\n';
	     cout << " 7 : Sort By InvoiceDate" << endl;
	     cout << '\n';
	     cout << " 0 : exit" << endl;
	     cout << '\n';

		cout << "Type which typ you want to sort : " << endl;
		int x;
		cin >> x;
        if(x == 7){
			quickSortD(data, 0, 150,x);
		}
		else{
			quickSort(data, 0, 150,x);
		}
	    for (int i = 1; i < 151; i++){
	        fout << data[i].InvN << ", " << data[i].STCODE << ", " << data[i].desT << ", " << data[i].quanT << ", " << data[i].invD << ", " << data[i].unitP << ", " << data[i].cusId << ", " << data[i].cntry <<'\n';
        }
        cout << "Number of Comparisions : " << comp << '\n';

        cout << "Number of Swaps : " << swaps << '\n';

		cout << "File created successfully!";

		csv_file.close();

		return 0;
	}
}

