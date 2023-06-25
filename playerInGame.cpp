#include "playerInGame.h"

PlayerInGame::PlayerInGame(const string& username, const string& password, int rank, int games_won, int games_loose
	, const string& phone_number, const string& address, const string& email, const int coins
	, vector<Card> cards, std::pair<int, int> base_pos,int place , Game prev_game= Game())

	: Player(username, password, rank, games_won, games_loose, phone_number
		, address, email, coins, prev_game)
{
	this->cards = cards;
	this->base_pos = base_pos;
	this->place = place;
}
PlayerInGame::PlayerInGame(const Player& player,int place, vector<Card> cards) : Player(player) {
	this->cards = cards;
	this->place = place;
}

void PlayerInGame::NewCards(std::vector<Card> cards) {
	this->cards = cards;
}

void PlayerInGame::PushCard(Card::CardType card_type, int number) {
	for (auto itr = cards.begin(); itr!= cards.end(); itr++) {
		if (itr->GetNumber() == number && itr->GetType() == card_type) {
			cards.erase(itr);
		}

	}
}

std::pair<int, int> PlayerInGame::GetBasePos() { return base_pos; }
void PlayerInGame::SetBasePos(std::pair<int, int> base_pos) { this->base_pos = base_pos; }


void PlayerInGame::Deal() {
	const int space_between_cards = 40;
	int rotation = 270 - place * 90 - cards.size() * space_between_cards;
    std::sort(cards.begin(),cards.end(),[](Card c1,Card c2){return (c1.GetType()>c2.GetType());});
	for (auto& card : cards) {
		card.show();
		card.PushTo(base_pos, rotation);
		rotation += space_between_cards;
	}



}
