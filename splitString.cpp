    void splitString(std::string const &str, const char delim,
			std::vector<std::string> &out)
{
	// construct a stream from the string
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

    
vector<string> split(const string& input, char token){
        vector<string> output;
        
        int start = 0;
        int idx = input.find(token, start);
        while (idx != string::npos)
        {
            output.push_back(input.substr(start, idx - start));
            start = idx + 1;
            idx = input.find(token, start);
        }
        
        output.push_back(input.substr(start));
        
        return output;
}