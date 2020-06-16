class Solution {
public:
    string validIPAddress(string IP) {
        if(validIP4Address(IP)) {
            return "IPv4";
        }
        if(validIP6Address(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
    
    bool validIP4Address(string IP) {
        if(count(IP.begin(), IP.end(), '.') != 3) { // ���ȼ�顰.���ĸ���
            return false;
        }

        // ���ա�.�����зָ�
        vector<string> parts;
        split(IP,parts, ".");
        if(parts.size() != 4) {
            return false;
        }
        
        // ��ʼ���ÿһ���Ƿ���ȷ
        for(string part : parts) {
           
            if(part.empty() || part.size() > 3 || part.size() != 1 && part[0] == '0') { // ����Ƿ�����������Ҫ��
                return false;
            }
            // ���ÿһ���ַ�
            for(char c : part) {
                if(!isdigit(c)) { // ����ַ��Ƿ�Ϊ����
                    return false;
                }
            }
            if(stoi(part) > 255) {
                return false;
            }
        }
        
        return true;
    }
    
    bool validIP6Address(string IP) {
        if(count(IP.begin(), IP.end(), ':') != 7) { // �ȼ�顰:���ĸ���
            return false;
        }
        // ���ա�:�����зָ�
        vector<string> parts;
        split(IP,parts,":");
        if(parts.size() != 8) {
            return false;
        }
        for(string part : parts) {
            if(part.empty() || part.size() > 4){
                return false;
            }
            for(char c : part) {
                // ���������ĸ�������ַ���false���������ĸ���Ǵ���F����false
                if(!isalnum(c) || (isalpha(c) && toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void split(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
      std::string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
      while(std::string::npos != pos2)
      {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
      if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }
    
};