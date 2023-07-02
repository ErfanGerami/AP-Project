#ifndef SERVERCARD_H
#define SERVERCARD_H


class ServerCard
{
public:

    typedef int CardType;
    const static CardType treasure;
    const static CardType map;
    const static CardType parrot;
    const static CardType flag;
    const static CardType pirate;
    const static CardType queen;
    const static CardType king;
    const static CardType unknown;
    ServerCard();
    ServerCard(CardType type, int number);
    ServerCard(const ServerCard &other);
    void operator=(const ServerCard &other);
    int GetNumber()const;
    int GetType()const;
    void SetNumber(int number);
    void SetType(CardType type);
    void ChangeCard(CardType type, int number);
private:
    int number;
    CardType type;

};

#endif // SERVERCARD_H
