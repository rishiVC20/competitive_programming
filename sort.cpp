#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>ans;
    for (int i=0; i<n; i++)
    {
        cin>>ans[i];
    }
    // for (int i=1; i<n; i++)
    // {
    //     for (int j=0; j<n-1; j++)
    //     {
    //         if (ans[j] > ans[j+1])
    //         {
    //             int temp = ans[j+1];
    //             ans[j+1] = ans[j];
    //             ans[j+1] = temp;
    //         }
    //     }
    // }
    sort(ans.begin(),ans.end());
    for (int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

vector<vector<int>>solve(vector<vector<int>> &matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int i=0; i<col; i++){
             int maxi = std::numeric_limits<int>::min();
            for (int j=0; j<row; j++){
                if (matrix[j][i] > maxi) {
                maxInColumn = matrix[j][i];
                }
            }
        }
        
        for (int row = 0; row < m; ++row) {
            if (answer[row][col] == -1) {
                answer[row][col] = maxInColumn;
            }
        }
    }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        
        vector<vector<int>> answer = solve(matrix);
         vector<vector<int>> solution
        for (const auto& row : answer) {
        for (int val : row) {
            // std::cout << val << " ";
            solution.push_back(val);
        }
        // std::cout << std::endl;
            
            return solution;
    
    }



    4. Multidimensional

5. Object-Oriented

Object-oriented databases (OODBs) are a type of database management system that extends the principles of object-oriented programming (OOP) to database design and management. Here are detailed aspects of object-oriented databases:

Structure:
1. Objects: Data is represented as objects, which are instances of classes in an object-oriented programming paradigm. Objects encapsulate both data and the methods (functions) that operate on
that data.
2. Classes: Classes define the structure and behavior of objects. They serve as blueprints for creating objects with shared characteristics and functionalities.
Components:
1. Attributes: Objects have attributes, which are properties or fieldsthat store data. Attributes correspond to the data members of a class.
2. Methods: Objects have methods, which are functions that perform operations on the data. Methods correspond to the member functions of a class.
3. Inheritance: OODBs support inheritance, allowing one class to inherit attributes and methods from another. This promotes code reuse and hierarchy in data modeling.
Key Concepts:
1. Encapsulation: Objects encapsulate both data and methods, providing a way to bundle related functionalities together and hide the internal details.
2. Polymorphism: OODBs support polymorphism, enabling objects of different classes to be treated interchangeably through a common interface.
3. Identity: Each object in the database has a unique identity, distinguishing it from other objects even if they have the same attribute values.
Example:
Consider a library database modeled using OODB. The &quot;Book&quot; class could have attributes like title, author, and publication year, as well as methods like checkOut() and returnBook(). Instances of the &quot;Book&quot; class would be objects in the database.
Advantages:
1. Modeling Complex Relationships: OODBs are well-suited for representing complex relationships and hierarchies in data, making them suitable for applications with intricate structures.
2. Object Reusability: The use of classes and inheritance promotes code reuse, reducing redundancy and improving maintainability.
Disadvantages:

1. Lack of Standardization: OODBs lack a standardized query language, making it challenging to work with them using a common interface like SQL in relational databases.
2. Complexity: Designing and implementing OODBs can be complex, and the learning curve for developers may be steeper compared to relational databases.
