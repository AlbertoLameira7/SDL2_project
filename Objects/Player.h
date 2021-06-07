
struct creditsWallet {
    creditsWallet(int credits) {
        _credits = credits;
    }

    int _credits;
};

class Player {

    public:
        Player(const char* name, creditsWallet* wallet);

        bool removeCreditsFromWallet();
        void insertCreditsToWallet(int value);
        creditsWallet* getWallet();

    private:
        const char* _name;
        creditsWallet* _wallet;
};
