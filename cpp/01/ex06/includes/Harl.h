class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    void ignore( void );

public:
    void complain( std::string level );
    Harl();
    ~Harl();
};
