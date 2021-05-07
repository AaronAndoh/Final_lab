#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <array>
using namespace std;
class rectBlocks{
		public:
	vector<string>Width;
	vector<string>Length;
	vector<string>Height;
		
	void read()
	
	{
				
	string width, height, length; //variables from file are here
	

	//number of lines
	int i = 0;

	ifstream Datafile("dataBlocksFile.Dat"); //opening the file.
	if (Datafile.is_open()) //if the file is open
	{
		//ignore first line
		string line;
		getline(Datafile, line);

		while (!Datafile.eof()) //while the end of file is NOT reached
		{
			getline(Datafile, width, ',');
			Width.push_back(width);
			getline(Datafile, height, ',');
			Height.push_back(height);
			getline(Datafile,length , '\n');
			Length.push_back(length);
			
	
			i += 1; //increment number of lines
		}
		Datafile.close(); //closing the file
		
		cout<<"Number of lines: " << i<<endl;
	}
	else cout << "Unable to open file"; //if the file is not open output
	
	//output values 
	cout << "width" << "\t" << "Height" << "\t" << "Length" << endl;
	for (int j = 0; j < i; j++) {
		cout << Width[j] << "\t" <<Height[j]<< "\t"  <<Length[j] << endl;
	
		}
	}

};
	
class squareBaseRectBlocks : public rectBlocks{
	public:
	string com[20];
	int x,y, count= 0;
	public:
	 void square(){
	 	
			for(x=0;x<20;x++){
				for(y=0;y<20;y++){
					if(Width[x]==Height[y]){
						com[count]=Height[y];
						count++;
				}
			}
				
		}
			cout.flush();
			cout<<"Total Number of Square:"<<count;
			for(int a=0; a<count;a++){
			cout<<"They are" <<com[a]<<endl;
		}
	}


	
};

class CubicBlock: public squareBaseRectBlocks{
	public:
	string comLength[20];
		void cuboid(){
			int x,y, count= 0;
			for(x=0;x<20;x++){
				for(y=0;y<20;y++){
					if(com[x]==Length[y]){
						comLength[count]=Length[y];
						count++;
					}
				}
				cout.flush();
				cout<<"Total Number of Square:"<<count;
				for(int a=0; a<count;a++){
					cout<< comLength[a];
				}
			}
}
	
};

class CylindricalBlock: public squareBaseRectBlocks{
	public:
int i,j, temp;
vector<string>Diameter;	
	
	void CylCalulations(int name[]){
	
	const float pie = 3.14;
	int SurfaceArea[12];
	 for(j=0; j<12; j++){
	 	SurfaceArea[j]= 2*(pie)*(name[j]/2)*(name[j])+2*pie*(name[j]/2)*(name[j]/2);
	 	 
	 }
	 for(i=0; i<12; i++)
    {
        for(j=i+1; j<12; j++)
        {
            //If there is a smaller element found on right of the array then swap it.
            if(SurfaceArea[j] < SurfaceArea[i])
            {
                temp = SurfaceArea[i];
                SurfaceArea[i] = SurfaceArea[j];
                SurfaceArea[j] = temp;
            }
            
    }
        
		}
    cout<<"                    "<<endl;
	 	 cout<<"----------------------------------------------------------"<<endl;
	 	 cout<<"Surface Area "<<endl;
	 	 for(i=0; i<12; i++)
    {
        cout<<SurfaceArea[i]<<endl; 
    }
    
    for(i=0; i<12; i++)
    {
        for(j=i+1; j<12; j++)
        {
            //If there is a smaller element found on right of the array then swap it.
            if(name[j] < name[i])
            {
                temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
            
    }
        
		}
    		cout<<"----------------------------------------------------------"<<endl;
    		cout<<"Diameters "<<endl;
             for(i=0; i<12; i++)
    {
        cout<<name[i]<<endl;
	}
	
		
	}
};	


class sphericalBlocks : public CubicBlock{
	public:
int i,j, temp;
vector<string>Diameter;	
	
	void Calulations(int name[]){
	for(i=0; i<12; i++)
    {
        for(j=i+1; j<12; j++)
        {
            //If there is a smaller element found on right of the array then swap it.
            if(name[j] < name[i])
            {
                temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
        }
    }
    //Printing the sorted array in ascending order
    cout<<"Elements of array in sorted ascending order:"<<endl;
    for(i=0; i<12; i++)
    {
        cout<<name[i]<<endl;
    }

const float pie = 3.14;
	int SurfaceArea[12];
	 for(j=0; j<12; j++){
	 	SurfaceArea[j]= 4/3*(pie)*(name[j]/2)*(name[j]/2)*(name[j]/2);
	 	 
	 }
	 
    cout<<"                    "<<endl;
	 	 cout<<"----------------------------------------------------------"<<endl;
	 	 cout<<"Surface Area of the diameter"<<endl;
	 	 for(i=0; i<12; i++)
    {
        cout<<SurfaceArea[i]<<endl; 
    }
    
	int volumes[12];
	 for(j=0; j<12; j++){
	 	volumes[j]= 4/3*(pie)*(name[j]/2)*(name[j]/2)*(name[j]/2);
	 	 
	 }
	 
    cout<<"                    "<<endl;
	 	 cout<<"----------------------------------------------------------"<<endl;
	 	 cout<<"Volume of the diameter"<<endl;
	 	 for(i=0; i<12; i++)
    {
        cout<<volumes[i]<<endl; 
    }
	 

}
	
};
	
	
	int main(void){
	int Diameter[12]= {7,4,8,10,10,6,3,12,11,5,7,5};
	
	
	sphericalBlocks SB;
	SB.read();
	SB.Calulations(Diameter);
	CylindricalBlock CB;
	CB.CylCalulations(Diameter);
	
}
	
