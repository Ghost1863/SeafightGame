#ifndef ABILITY_RESULT
#define ABILITY_RESULT

class AbilityResult {	

public:	
	virtual int getDamage();
	virtual bool getIsShipDestroyed();
	virtual bool getIsSegmentFound();
};

class DoubleDamageResult :public AbilityResult {
private:
	int damage;
	bool isShipDestroyed;
public:
	DoubleDamageResult(int damage,bool isDestroyed) :damage(damage), isShipDestroyed(isDestroyed) {};
	int getDamage() override;
	bool getIsShipDestroyed() override;
	bool getIsSegmentFound() override;
};

class ScannerResult :public AbilityResult {
private:
	bool isSegmentFound;
public:
	ScannerResult(bool isFound) : isSegmentFound(isFound) {};
	int getDamage() override;
	bool getIsShipDestroyed() override;
	bool getIsSegmentFound() override;
};

class RandomHitResult :public AbilityResult {
	bool isShipDestroyed;
public:
	RandomHitResult(bool isDestroyed) :isShipDestroyed(isDestroyed) {};
	int getDamage() override;
	bool getIsShipDestroyed() override;
	bool getIsSegmentFound() override;
};
#endif 
