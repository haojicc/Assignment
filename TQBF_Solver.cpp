#include <iostream>
#include <vector>

using namespace std;

class solution{
public:
    bool check(vector<vector<int>>& formula, vector<int>& quantifiers, int nums){// qunatifiers and assisnment are both 1-index.
        printM(formula);
        cout << "||" << nums << endl;
        cout << "&&" << quantifiers.size() << endl;
        if(nums > quantifiers.size()){
            if(checkFormula(formula) == 1){
                return true;
            }else{
                return false;
            }
        }
        //check x_nums is Exist(1) or Any(0).
        bool ans;
        int n = nums + 1;
        vector<vector<int>> formula0 = updateFormula(formula, nums, 0);
        vector<vector<int>> formula1 = updateFormula(formula, nums, 1);
        cout << "formula0:" << endl;
        printM(formula0);
        cout << "\n" << "formula1:" << endl;
        printM(formula1);
        cout << "\n";
        if(quantifiers[nums] == 1){
            ans = check(formula0, quantifiers, n);
            ans = ans || check(formula1, quantifiers, n);
        }else{
            ans = check(formula0, quantifiers, n);
            ans = ans && check(formula1, quantifiers, n);
        }
        return ans;
    }

private:
    int checkFormula(vector<vector<int>>& formula){//0 is false. 1 is true. 2 is undetermined.
        for(auto item: formula){
            //0 is false. 1 is true. integer is undetermined.
            int temp = 0;
            for(auto ele: item){
                if(ele == 1) {
                    temp = 1;
                    break;
                }else if(ele != 0){
                    temp = 2;
                    break;
                }
            }
            if(temp == 0) {
                return 0;
            }else if(temp == 2){
                return 2;
            }
        }
        return 1;
    }

    vector<vector<int>> updateFormula(vector<vector<int>>& formula, int num, int ass){ // 1-index
        int m = formula.size();
        vector<vector<int>> updatedFormula(m);
        for(int i = 0; i < m; i++){
            int n = formula[i].size();
            updatedFormula[i].resize(n);
            for(int j = 0; j < n; j++){
                if(formula[i][j] == 0){
                    updatedFormula[i][j] = 0;
                }else if(formula[i][j] == 1){
                    updatedFormula[i][j] = 1;
                }else{
                    if(formula[i][j] == 2 * num){
                        updatedFormula[i][j] = ass;
                    }else if(formula[i][j] == 2 * num + 1){
                        updatedFormula[i][j] = 1 - ass;
                    }else{
                        updatedFormula[i][j] = formula[i][j];
                    }
                }
            }
        }

        return updatedFormula;
    }

    void printM(vector<vector<int>>& formula){
        for(auto item: formula){
            for(auto ele: item){
                cout << ele;
            }
        }
    }
};

int main() {
    vector<vector<int>> formula{{4,6,8,10},{7,10},{5,6,12}};
    vector<int> quantifiers{0,1,0,1,0,1};

    solution obj;
    bool rs = obj.check(formula, quantifiers, 1);

    std::cout << rs << std::endl;
    return 0;
}
