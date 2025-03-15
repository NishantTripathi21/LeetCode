class Spreadsheet {
public:
    unordered_map<string, int> cellValues;

    bool check(string &s) {
        return s.size() > 1 && isalpha(s[0]) && isdigit(s[1]);
    }
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        cellValues[cell] = value;
    }
    
    void resetCell(string cell) {
        cellValues.erase(cell);
    }
    
    int getValue(string formula) {
        if (formula[0] == '=') {
            formula = formula.substr(1);
            size_t plusPos = formula.find('+');
            string left = formula.substr(0, plusPos);
            string right = formula.substr(plusPos + 1);
            
            int leftValue = check(left) ? cellValues[left] : stoi(left);
            int rightValue = check(right) ? cellValues[right] : stoi(right);
            
            return leftValue + rightValue;
        }
        return stoi(formula);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
