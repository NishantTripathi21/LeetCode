class ProductOfNumbers {
public:
    //vector<int>data;
    vector<int>prefixProduct;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        //data.push_back(num);
        int back = 1;
        int prod = num;
        if( prefixProduct.size() >= 1){
            back = prefixProduct.back();
        }
        prod = back * prod;
        prefixProduct.push_back(prod);
        if( prod == 0){
            prefixProduct.clear();
        }
    }
    
    int getProduct(int k) {
        if( k > prefixProduct.size())return 0;
        int n = prefixProduct.size();
        if( k == n)return prefixProduct[n -1];
        int d1 = prefixProduct[n -1];
        int d2 = prefixProduct[n - 1 - k];
        return d1/d2;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
