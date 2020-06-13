class RandomizedSet {
    // �о�java�Ĳ���ʱ�临�ӶȲ���C++����ȷ
    ArrayList<Integer> elements;
    HashMap<Integer,Integer> hash_table;
    java.util.Random rand;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        elements = new ArrayList<Integer>();
        hash_table = new HashMap<Integer,Integer>();
        rand = new java.util.Random(42);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(hash_table.containsKey(val)) { // �������val����ֱ�ӷ���false
            return false;
        }
        // hash_table�м�¼val��ֵ��val��Ӧ�������е�����λ��
        hash_table.put(val, elements.size());
        elements.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!hash_table.containsKey(val)) { // ���������val����ֱ�ӷ���false
            return false;
        }
        int loc = hash_table.get(val); // ��ȡval�������ж�Ӧ������
        if(loc < elements.size() - 1) { // �����ʱɾ����val�������һλ��������һλ��val���н���
            int lastone = elements.get(elements.size() - 1); // ��ȡ���һλ������
            elements.set(loc, lastone); // Ҫ��ɾ����val��Ӧ��λ��������Ϊ���һλ�����ݣ����һλ���Բ�������Ϊval����ΪҪ��ɾ����
            hash_table.put(lastone, loc); // ͬʱ�޸�table�����һλ��Ӧ������λ��
            
        }
        hash_table.remove(val);
        elements.remove(elements.size() - 1); // ɾ����Ԫ�أ���ɾ����λ���ǵ�һ���������һ��ʱ��O(1)
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return elements.get(rand.nextInt(elements.size()));
    }
    
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */