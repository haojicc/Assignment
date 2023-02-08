#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>

class initialization {
    int L; // The number of char in set S.
    int n; // The number of hash functions.
    int j; // The number of subsets of S.
public:
    initialization(int l, int n, int j) : L(l), n(n), j(j) {};
    /*
     * Initialize sparse matrix M, which each column has no more than 1% nonzero.
     * Set S = {0, 1, 2, 3, 4, ..., L-1}. Generate (randomly chosen) S1, S2, ..., SQ that are distinct subsets of S.
     * Sparse matrix M whose rows represent the elements of S and whose columns represent the S_j's.
     * If M[i][j] = true, Subset S_j include item i. i include S = {0, 1, 2, 3, 4, ..., L-1}.
     * */
    std::vector<std::vector<bool>> initializeM(){
        std::random_device seed_gen;
        std::default_random_engine engine(seed_gen());
        std::uniform_real_distribution<> dense(0,0.01);//Create a random real number between 0-0.01

        std::vector<std::vector<bool>> sparseMatrixM(L, std::vector<bool>(j, false));
        for(int i = 0; i < j; i++){
            double nonzeroDense = dense(engine);
            int numberOfSubset = L * nonzeroDense;
            std::uniform_int_distribution<> subset(0,L-1);
            while( numberOfSubset >= 0 ){
                int indexOfChar = subset(engine);
                if(sparseMatrixM[indexOfChar][i] == false){
                    numberOfSubset--;
                    sparseMatrixM[indexOfChar][i] = true;
                }
            }
        }
        return sparseMatrixM;
    }
    /*
     * Initialize SIG_ij = infinite(INT_MAX), for all i, j.
     * */
    std::vector<std::vector<int>> initializeSIG(){
        std::vector<std::vector<int>> SIG(n, std::vector<int> (j, INT_MAX));
        return SIG;
    }
    /*
     * By Sieve of Eratosthenes find the first nth primes(include 1).
     * */
    std::vector<int> initializeHashFuncChar(){
        std::vector<int> primeNum = findPrime(L);// Function findPrime is the process of Sieve of Eratosthenes. And find all the prime numbers in [1~L].
        std::vector<int> hashFuncChar(primeNum.begin(), primeNum.begin() + n); // copy the first nth primes.
        return hashFuncChar;
    }
private:
    std::vector<int> findPrime(int L){ //the process of Sieve of Eratosthenes.
        std::vector<int> prime(L+1);
        for(int i = 0; i <= L; i++){
            prime[i] = i;
        }
        for(int i  = 2; i <= L; i++){
            if(prime[i] != 0){
                for(int j = 2; i*j <= L; j++){
                    prime[i * j] = 0;
                }
                if(getMax(prime, L) <= i * i){
                    break;
                }
            }
        }
        std::vector<int> primeNum;
        for(int i = 1; i <= L; i++){
            if(prime[i]){
                primeNum.push_back(i);
            }
        }
        return primeNum;
    }
    int getMax(std::vector<int> prime, int index){  //This is an auxiliary function of findPrime
        for (int i = index;; i--)
            if (prime[i])
                return prime[i];
    }
};
class calculateSIG{
    std::vector<std::vector<int>> SIG;
    std::vector<std::vector<bool>> sparseMatrixM;
    std::vector<int> hashFuncChar;
    int c;
public:
    calculateSIG(const std::vector<std::vector<int>> &sig, const std::vector<std::vector<bool>> &sparseMatrixM,
                 const std::vector<int> &hashFuncChar, int c) : SIG(sig), sparseMatrixM(sparseMatrixM),
                                                                hashFuncChar(hashFuncChar), c(c) {};

/*
 *  if sparseMatrixM[row][column] = 1: need to update SIG[i][column] with h_i(x), which h_i(x)(from 0 to n-1) is the i_th of hash function.
 *      long temp = hashFunction(row, i)
 *      SIG[i][column] = min(SIG[i][column], temp);
 * */
    void updateSIG(){
        for(int row = 0; row < sparseMatrixM.size(); row++){
            for(int column = 0; column < sparseMatrixM[0].size(); column++){
                if(sparseMatrixM[row][column] == true){
                    for(int i = 0; i < SIG.size(); i++){
                        long temp = hashFunction(row, i);
                        SIG[i][column] = std::min(SIG[i][column], (int)temp);
                    }
                }
            }
        }
    }

    std::vector<std::vector<int>> getSIG(){
        return SIG;
    }

    void printSIG(){
        for(int i = 0; i < SIG.size(); i++){
            std::cout << "|" ;
            for(int j = 0; j < SIG[0].size(); j++){
                std::cout << SIG[i][j] << "  ";
            }
            std::cout << "|" << std::endl;
        }
    }

private:
    int L = sparseMatrixM.size();
    long hashFunction(int x, int i){  //hi(x) = p(i)x + 2 mod L   hashFuncChar[i] is the i-th prime number.
        long hashValue = ((long)hashFuncChar[i] * x + 1) % L;
        return hashValue;
    }
};
class calculateJaccardSimilarity{
    std::vector<std::vector<int>> SIG;
    std::vector<std::vector<bool>> sparseMatrixM;
    int j;
    int k;
public:
    calculateJaccardSimilarity(const std::vector<std::vector<int>> &sig,
                               const std::vector<std::vector<bool>> &sparseMatrixM, int j, int k) : SIG(sig),
                                                                                                    sparseMatrixM(
                                                                                                            sparseMatrixM),
                                                                                                    j(j), k(k) {};

    double methodByM(){
        double jaccardSimilarityByM;
        int x = 0; // There are x rows with 1 in both columns.
        int y = 0; // There are y rows with a 1 in only 1 column.
        int z = 0; // There are z rows with 0 in both columns.
        for(int row = 0; row < sparseMatrixM.size(); row++){
            if(sparseMatrixM[row][j] == 1 && sparseMatrixM[row][k] == 1){
                x++;
            }else if(sparseMatrixM[row][j] == 1 || sparseMatrixM[row][k] == 1){
                y++;
            }else{
                z++;
            }
        }
        jaccardSimilarityByM = (double)x / (x + y);
        return jaccardSimilarityByM;
    }

    double methodBySIG(){
        double jaccardSimilarityBySIG;
        int count = 0;
        for(int row = 0; row < SIG.size(); row++){
            if(SIG[row][j] == SIG[row][k]){
                count++;
            }
        }
        jaccardSimilarityBySIG = (double)count / SIG.size();
        return jaccardSimilarityBySIG;
    }
};

void printMatrix(std::vector<std::vector<bool>>& M){
    for(int i = 0; i < M[0].size(); i++){
        std::cout << "|" ;
        int count = 0;
        for(int j = 0; j < M.size(); j++){
            if(M[j][i] == 1){
                count++;
            }
            std::cout << M[j][i];
        }
        double dence = (double)count / M.size();
        std::cout << "|" << dence << std::endl;
    }
} // Check the dence of M
void printM(std::vector<std::vector<bool>>& M){
    std::cout << "{" ;
    for(auto item: M){
        std::cout << "{" ;
        for(auto e: item){
            std::cout << e << ",";
        }
        std::cout << "} ," << std::endl;
    }
    std::cout << "}" ;
}
void printPrime(std::vector<int>& p){
    for(int i = 0; i < p.size(); i++){
        std::cout << p[i] << "  ";
        if(i % 10 == 0){
            std::cout << "|" << std::endl;
        }
    }
} // Check the prime numbers.

int main() {
    std::cout << "First use the example in the class lecture notes (including its h1(x) and h2(x) definitions):" << std::endl;
    int firstExampleL = 5; // The number of char in set S.
    int firstExampleN = 2; // The number of hash functions.
    int firstExampleJ = 3; // The number of subsets of S.
    int firstExampleC = 1; //The constant of hash function. When hi(x) = p(i)x + 1 , then firstExampleC = 1.

    initialization firstExample_1(firstExampleL, firstExampleN, firstExampleJ); //Prepare for calculation.
    std::vector<int> firstExampleP {1, 3};
    std::vector<std::vector<bool>> firstExampleM {
            {1, 0, 1},
            {0, 0, 1},
            {1, 1, 0},
            {0, 1, 1},
            {1, 0, 0}
    };
    std::vector<std::vector<int>> firstExampleSIG = firstExample_1.initializeSIG();

    calculateSIG firstExample_2(firstExampleSIG, firstExampleM, firstExampleP, firstExampleC);
    firstExample_2.updateSIG();//update firstExampleSIG.
    firstExample_2.printSIG();//print firstExampleSIG.
    std::vector<std::vector<int>> newSIG = firstExample_2.getSIG();

    calculateJaccardSimilarity firstExample_3(newSIG, firstExampleM, 0, 2); // const std::vector<std::vector<int>> &sig, const std::vector<std::vector<bool>> &sparseMatrixM, int secondExampleJ, int k
    std::cout << "Calculating J(Sj,Sk) using M's data structure: " << firstExample_3.methodByM() << "\nCalculating J_SIG(Sj,Sk) using firstExampleSIG's data structure: " << firstExample_3.methodBySIG() << std::endl;

//    printMatrix(firstExampleM); //Check the dence of M.
//    printPrime(firstExampleP); //Check the prime numbers.

    std::cout << "Finally use a much larger example with L = ~2000:" << std::endl;
    int secondExampleL = 1500;// The number of char in set S.
    int secondExampleN = 200;// The number of hash functions.
    int secondExampleJ = 3;// The number of subsets of S.
    int secondExampleC = 2;//The constant of hash function. When hi(x) = p(i)x + 2 , then secondExampleC = 2.

    initialization secondExample_1(secondExampleL, secondExampleN, secondExampleJ);
    std::vector<int> secondExampleP = secondExample_1.initializeHashFuncChar();
    std::vector<std::vector<bool>> secondExampleM = secondExample_1.initializeM();
    std::vector<std::vector<int>> secondExampleSIG = secondExample_1.initializeSIG();

    printM(secondExampleM); //Check the dence of M.

    calculateSIG secondExample_2(secondExampleSIG, secondExampleM, secondExampleP, secondExampleC);
    secondExample_2.updateSIG();//update firstExampleSIG.
    secondExample_2.printSIG();//print firstExampleSIG.
    std::vector<std::vector<int>> secondExampleNewSIG = secondExample_2.getSIG();

    calculateJaccardSimilarity secondExample_3(secondExampleNewSIG, secondExampleM, 0, 2);
    std::cout << "Calculating J(Sj,Sk) using M's data structure: " << secondExample_3.methodByM() << "\nCalculating J_SIG(Sj,Sk) using firstExampleSIG's data structure: " << secondExample_3.methodBySIG() << std::endl;

    return 0;
}
