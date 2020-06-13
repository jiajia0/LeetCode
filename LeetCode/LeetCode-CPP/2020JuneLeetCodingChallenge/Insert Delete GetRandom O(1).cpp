class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash_table[val] != 0) {
            return false;
        }
        // ��һ����Ӹ�������1
        n++;
        hash_table[val] = n; // val��Ӧ��ֵ��val�������е�����+1
        if(elements.size() >= n) { // ��Ҫע������ռ��λ�ù�ϵ��ȷ��hashtable�е�val��Ӧ�������е�λ��Ϊn
            elements[n-1] = val;
        }
        elements.push_back(val); // ���������������鿴��
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // ���==0����˵����ʱ������val
        if(hash_table[val] == 0) {
            return false;
        }
        int loc = hash_table[val]; // �ҵ�val��Ӧ�����е�����
        // loc < n ʱ˵����ʱɾ����Ԫ�ز�����������һλ����Ҫ���������Ϊ�뵱ǰɾ����λ��
        if(loc < n) { // �൱�ڰ�Ҫɾ����Ԫ�ر�������е����һ��
            int lastone = elements[n - 1]; // �ҵ����һλԪ��
            elements[loc - 1] = lastone; // ��Ҫɾ��val��λ������Ϊ���һλԪ��
            hash_table[lastone] = loc; // ��Ӧ��hashtable�е�lastoneλ��ҲҪ�����޸�
        }
        hash_table[val] = 0; // hashtable��ɾ��
        elements[n - 1] = 0; // ������ɾ�������Ϊ0��
        n--;
        // cout << "delete after" << val << ":";
        // for(auto n : elements) {
        //     cout << n << " ";
        // }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return elements[rand() % n];
    }
private:
    unordered_map<int,int> hash_table; // ��hashtable������Ƿ���ڣ��Լ���ȡ����
    vector<int> elements; // �������Ԫ�أ����Ը����������ֱ�ӻ�ȡ����
    int n; // ������ʶ�ж��ٸ�Ԫ��
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */