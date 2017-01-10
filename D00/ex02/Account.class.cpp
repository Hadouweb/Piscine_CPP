#include "Account.class.hpp"
#include <iostream>

Account::Account(int initial_deposit) {
	this->_accountIndex = 0;
	this->_accountIndex = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	this->_accountIndex = Account::_nbAccounts - 1;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created";
	std::cout << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed";
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount() - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->checkAmount();
		std::cout << ";withdrawal:refused";
		std::cout << std::endl;
		return 0;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount() + withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

	return 1;
}

int Account::checkAmount(void) const {
	return Account::_amount;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void Account::_displayTimestamp(void) {
	time_t ltime;
	struct tm *t;

	ltime = time(NULL);
	t = localtime(&ltime);

	std::cout << "[";
	std::cout << t->tm_year + 1900;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << t->tm_mon + 1;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << t->tm_mday;
	std::cout << "_";
	std::cout << t->tm_hour;
	std::cout << t->tm_min;
	std::cout << t->tm_sec;
	std::cout << "] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;