#pragma once

void showMenu();
int getVehicleTypeInputWithShowingMenu(int* vehicleType);
int getDurationInput(int *durationInput);
double calculateBill(int vehicleType, int vehicleHourDuration, double& bill, double& income);
