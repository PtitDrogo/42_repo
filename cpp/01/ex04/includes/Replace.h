class Replace
{
private:
    std::string _filename;
    std::string _outfile_name;
    std::string _to_find;
    std::string _to_replace;

public:
    void find_and_replace(char const *file_name, char const *s1, char const *s2);
    Replace();
    ~Replace();
};
