#ifndef _CAPYCITYSIM_H_
#define _CAPYCITYSIM_H_

class CapyCitySim
{
private:
	int rows;
	int cols;
	int** buildPlan;
		

	int** createMaps(int rows, int cols);

public:
	CapyCitySim(int rows, int cols);

	~CapyCitySim();

	int getBuildPlan(int x, int y);

	void setRows(int rows);

	int getRows();

	void setCols(int cols);

	int getCols();

	void showMap();

	void place();

	void deleteArea();

};
#endif
