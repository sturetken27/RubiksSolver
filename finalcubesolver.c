#pragma config(Sensor, S1,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Touch)
#pragma config(Sensor, S3,     ,               sensorEV3_Ultrasonic)

int myCube[6][4];
int moves[14];
int counter = 0;
const int plusSome = 7;
const int correction =1;

void moveArmAway()
{
	nMotorEncoder[motorB] = 0;

	while(nMotorEncoder[motorB] < 95)
	{
		motor[motorB] = 20;
	}
	motor[motorB] = 0;
}


void moveArmBack()
{
	nMotorEncoder[motorB] = 0;

	while(nMotorEncoder[motorB] > -95)
	{
		motor[motorB] = -20;
	}
	motor[motorB] = 0;
}


void rotCube(int turns)
{
	nMotorEncoder[motorA] = 0;
	int rotDeg = 0;
	rotDeg = turns*90;

	while (nMotorEncoder[motorA] < rotDeg)
	{
			motor[motorA] = 5;
  }
  motor[motorA] = 0;
  while (nMotorEncoder[motorA] > rotDeg)
	{
			motor[motorA] = -5;
  }
	motor[motorA] = 0;
	wait1Msec(50);
}


void rotCubeBW(int turns)
{
	nMotorEncoder[motorA] = 0;
	int rotDeg = 0;
	rotDeg = turns*-90;

	while (nMotorEncoder[motorA] > rotDeg)
	{
			motor[motorA] = -5;
  }
	motor[motorA] = 0;
	while (nMotorEncoder[motorA] < rotDeg)
	{
			motor[motorA] = 5;
  }
  motor[motorA] = 0;
	wait1Msec(50);
}


void rotBot (int turns)
{
	nMotorEncoder[motorA] = 0;
	int rotDeg = 0;
	rotDeg = turns*90;

	moveArmBack();
	wait1Msec(250);

	while (nMotorEncoder[motorA] < rotDeg + plusSome)
	{
			motor[motorA] = 20;
  }
  motor[motorA] = 0;
  while (nMotorEncoder[motorA] > rotDeg-correction)
	{
			motor[motorA] = -5;
  }
	motor[motorA] = 0;
	wait1Msec(50);
	moveArmAway();
	wait1Msec(50);
}


void rotBotBW(int turns)
{
	nMotorEncoder[motorA] = 0;
	int rotDeg = 0;
	rotDeg = turns*-90;

	moveArmBack();
	wait1Msec(250);

	while (nMotorEncoder[motorA] > rotDeg - plusSome)
	{
			motor[motorA] = -20;
  }
	motor[motorA] = 0;
	while (nMotorEncoder[motorA] < rotDeg+correction)
	{
			motor[motorA] = 5;
  }
	motor[motorA] = 0;
	wait1Msec(50);
	moveArmAway();
	wait1Msec(50);
}


void flipCube (int flips)
{
	nMotorEncoder[motorB] = 0;
	int nums = 0;

	while (nums < flips)
	{
			while(nMotorEncoder[motorB] > -190)
		  {
		  	motor[motorB] = -25;
			}
			while(nMotorEncoder[motorB] < -90)
			{
				motor[motorB] = 30;
			}
			nums++;
  }
	wait1Msec(50);

	while(nMotorEncoder[motorB] < 0)
	{
		motor[motorB] = 20;
	}
}


void scanFace (int side)
{
	nMotorEncoder[motorC] = 0;

	int count = 0;
	while (count < 4)
	{
			while(nMotorEncoder[motorC] < 155)
		  {
		  	motor[motorC] = 7;
			}
			motor[motorC] = 0;
			myCube[side][count] = (int) SensorValue[S1];
			wait1Msec(250);
			displayString(3,"%d",myCube[side][count]);
			wait1Msec(250);
			rotCube(1);
			count++;
  }
  while(nMotorEncoder[motorC] > 0)
	{
		motor[motorC] = -7;
	}
	motor[motorC] = 0;
  wait1Msec(50);
}


void scanCube()
{
	int side = 0;
	while(side < 4)
	{
		scanFace(side);
		flipCube(1);
		side++;
	}
	rotCube(1);
	flipCube(1);
	scanFace(4);
	flipCube(1);
	flipCube(1);
	scanFace(5);
	flipCube(1);
	rotCubeBW(1);
}

void U()
{
		rotBotBW(1);
		wait1Msec(50);
		rotCube(1);
}

void UPrim()
{
		rotBot(1);
		wait1Msec(50);
		rotCubeBW(1);
}

void DPrim()
{
		rotBot(1);
		wait1Msec(50);
}

void Dd()
{
		rotBotBW(1);
		wait1Msec(50);
}

void R()
{
		flipCube(1);
		rotCube(1);
		flipCube(1);
		rotBotBW(1);
		flipCube(1);
		rotCube(1);
		flipCube(1);
		flipCube(1);
}

void RPrim()
{
		flipCube(1);
		rotCube(1);
		flipCube(1);
		rotBot(1);
		flipCube(1);
		rotCube(1);
}

void L()
{
		flipCube(1);
		rotCubeBW(1);
		flipCube(1);
		rotBotBW(1);
		rotCubeBW(1);
		flipCube(1);
		rotCubeBW(1);
		flipCube(1);
		flipCube(1);
		flipCube(1);
}

void LPrim()
{
		flipCube(1);
		rotCube(1);
		flipCube(1);
		flipCube(1);
		flipCube(1);
		rotBot(1);
		flipCube(1);
		rotCubeBW(1);
}

void F()
{
		flipCube(1);
		flipCube(1);
		flipCube(1);
		rotBotBW(1);
		flipCube(1);
}

void FPrim()
{
		flipCube(1);
		flipCube(1);
		flipCube(1);
		rotBot(1);
		flipCube(1);
}

void B()
{
		flipCube(1);
		rotBotBW(1);
		flipCube(1);
		flipCube(1);
		flipCube(1);
}

void BPrim()
{
		flipCube(1);
		rotBot(1);
		flipCube(1);
		flipCube(1);
		flipCube(1);
}

bool isSolved()
	{
		if(myCube[0][0] == myCube[0][1] && myCube[0][1] == myCube[0][2] && myCube[0][2] == myCube[0][3])
		{
			if(myCube[1][0] == myCube[1][1] && myCube[1][1] == myCube[1][2] && myCube[1][2] == myCube[1][3])
			{
				if(myCube[2][0] == myCube[2][1] && myCube[2][1] == myCube[2][2] && myCube[2][2] == myCube[2][3])
				{
					if(myCube[3][0] == myCube[3][1] && myCube[3][1] == myCube[3][2] && myCube[3][2] == myCube[3][3])
					{
						if(myCube[4][0] == myCube[4][1] && myCube[4][1] == myCube[4][2] && myCube[4][2] == myCube[4][3])
						{
							if(myCube[5][0] == myCube[5][1] && myCube[5][1] == myCube[5][2] && myCube[5][2] == myCube[5][3])
							{
								return true;
							}
						}
					}
				}
			}
		}
			return false;
  }

//U = 1, U' = 2, D = 3, D' = 4, R = 5, R' = 6, L = 7, L' = 8, F = 9, F' = 10, B = 11, B' = 12
void applyMove(int moveType)
{
	int temp1 = 0, temp2 = 0, temp3 = 0;

	if(moveType == 1)
	{
		temp1 = myCube[0][0];
		myCube[0][0] = myCube[0][1];
		myCube[0][1] = myCube[0][2];
		myCube[0][2] = myCube[0][3];
		myCube[0][3] = temp1;

		temp2 = myCube[1][2];
		myCube[1][2] = myCube[4][2];
		myCube[4][2] = myCube[3][0];
		myCube[3][0] = myCube[5][0];
		myCube[5][0] = temp2;

		temp3 = myCube[1][3];
		myCube[1][3] = myCube[4][3];
		myCube[4][3] = myCube[3][1];
		myCube[3][1] = myCube[5][1];
		myCube[5][1] = temp3;
	}
	else if(moveType == 2)
	{
		temp1 = myCube[0][0];
		myCube[0][0] = myCube[0][3];
		myCube[0][3] = myCube[0][2];
		myCube[0][2] = myCube[0][1];
		myCube[0][1] = temp1;

		temp2 = myCube[1][2];
		myCube[1][2] = myCube[5][0];
		myCube[5][0] = myCube[3][0];
		myCube[3][0] = myCube[4][2];
		myCube[4][2] = temp2;

		temp3 = myCube[1][3];
		myCube[1][3] = myCube[5][1];
		myCube[5][1] = myCube[3][1];
		myCube[3][1] = myCube[4][3];
		myCube[4][3] = temp3;
	}
	else if(moveType == 3)
	{
		temp1 = myCube[2][0];
		myCube[2][0] = myCube[2][1];
		myCube[2][1] = myCube[2][2];
		myCube[2][2] = myCube[2][3];
		myCube[2][3] = temp1;

		temp2 = myCube[4][0];
		myCube[4][0] = myCube[1][0];
		myCube[1][0] = myCube[5][2];
		myCube[5][2] = myCube[3][2];
		myCube[3][2] = temp2;

		temp3 = myCube[4][1];
		myCube[4][1] = myCube[1][1];
		myCube[1][1] = myCube[5][3];
		myCube[5][3] = myCube[3][3];
		myCube[3][3] = temp3;
	}
	else if(moveType == 4)
	{
		temp1 = myCube[2][0];
		myCube[2][0] = myCube[2][3];
		myCube[2][3] = myCube[2][2];
		myCube[2][2] = myCube[2][1];
		myCube[2][1] = temp1;

		temp2 = myCube[4][0];
		myCube[4][0] = myCube[3][2];
		myCube[3][2] = myCube[5][2];
		myCube[5][2] = myCube[1][0];
		myCube[1][0] = temp2;

		temp3 = myCube[4][1];
		myCube[4][1] = myCube[3][3];
		myCube[3][3] = myCube[5][3];
		myCube[5][3] = myCube[1][1];
		myCube[1][1] = temp3;
	}
	else if(moveType == 5)
	{
		temp1 = myCube[5][0];
		myCube[5][0] = myCube[5][1];
		myCube[5][1] = myCube[5][2];
		myCube[5][2] = myCube[5][3];
		myCube[5][3] = temp1;

		temp2 = myCube[0][0];
		myCube[0][0] = myCube[3][0];
		myCube[3][0] = myCube[2][0];
		myCube[2][0] = myCube[1][0];
		myCube[1][0] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[3][3];
		myCube[3][3] = myCube[2][3];
		myCube[2][3] = myCube[1][3];
		myCube[1][3] = temp3;
	}
	else if(moveType == 6)
	{
		temp1 = myCube[5][0];
		myCube[5][0] = myCube[5][3];
		myCube[5][3] = myCube[5][2];
		myCube[5][2] = myCube[5][1];
		myCube[5][1] = temp1;

		temp2 = myCube[0][0];
		myCube[0][0] = myCube[1][0];
		myCube[1][0] = myCube[2][0];
		myCube[2][0] = myCube[3][0];
		myCube[3][0] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[1][3];
		myCube[1][3] = myCube[2][3];
		myCube[2][3] = myCube[3][3];
		myCube[3][3] = temp3;
	}
	else if(moveType == 7)
	{
		temp1 = myCube[4][0];
		myCube[4][0] = myCube[4][1];
		myCube[4][1] = myCube[4][2];
		myCube[4][2] = myCube[4][3];
		myCube[4][3] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[1][1];
		myCube[1][1] = myCube[2][1];
		myCube[2][1] = myCube[3][1];
		myCube[3][1] = temp2;

		temp3 = myCube[0][2];
		myCube[0][2] = myCube[1][2];
		myCube[1][2] = myCube[2][2];
		myCube[2][2] = myCube[3][2];
		myCube[3][2] = temp3;
	}
	else if(moveType == 8)
	{
		temp1 = myCube[4][0];
		myCube[4][0] = myCube[4][3];
		myCube[4][3] = myCube[4][2];
		myCube[4][2] = myCube[4][1];
		myCube[4][1] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[3][1];
		myCube[3][1] = myCube[2][1];
		myCube[2][1] = myCube[1][1];
		myCube[1][1] = temp2;

		temp3 = myCube[0][2];
		myCube[0][2] = myCube[3][2];
		myCube[3][2] = myCube[2][2];
		myCube[2][2] = myCube[1][2];
		myCube[1][2] = temp3;
	}
	else if(moveType == 9)
	{
		temp1 = myCube[3][0];
		myCube[3][0] = myCube[3][1];
		myCube[3][1] = myCube[3][2];
		myCube[3][2] = myCube[3][3];
		myCube[3][3] = temp1;

		temp2 = myCube[0][2];
		myCube[0][2] = myCube[4][1];
		myCube[4][1] = myCube[2][0];
		myCube[2][0] = myCube[5][1];
		myCube[5][1] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[4][2];
		myCube[4][2] = myCube[2][1];
		myCube[2][1] = myCube[5][2];
		myCube[5][2] = temp3;
	}
	else if(moveType == 10)
	{
		temp1 = myCube[3][0];
		myCube[3][0] = myCube[3][3];
		myCube[3][3] = myCube[3][2];
		myCube[3][2] = myCube[3][1];
		myCube[3][1] = temp1;

		temp2 = myCube[0][2];
		myCube[0][2] = myCube[5][1];
		myCube[5][1] = myCube[2][0];
		myCube[2][0] = myCube[4][1];
		myCube[4][1] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[5][2];
		myCube[5][2] = myCube[2][1];
		myCube[2][1] = myCube[4][2];
		myCube[4][2] = temp3;
	}
	else if(moveType == 11)
	{
		temp1 = myCube[1][0];
		myCube[1][0] = myCube[1][1];
		myCube[1][1] = myCube[1][2];
		myCube[1][2] = myCube[1][3];
		myCube[1][3] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[5][0];
		myCube[5][0] = myCube[2][3];
		myCube[2][3] = myCube[4][0];
		myCube[4][0] = temp2;

		temp3 = myCube[0][0];
		myCube[0][0] = myCube[5][3];
		myCube[5][3] = myCube[2][2];
		myCube[2][2] = myCube[4][3];
		myCube[4][3] = temp3;
	}
	else if(moveType == 12)
	{
		temp1 = myCube[1][0];
		myCube[1][0] = myCube[1][3];
		myCube[1][3] = myCube[1][2];
		myCube[1][2] = myCube[1][1];
		myCube[1][1] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[4][0];
		myCube[4][0] = myCube[2][3];
		myCube[2][3] = myCube[5][0];
		myCube[5][0] = temp2;

		temp3 = myCube[0][0];
		myCube[0][0] = myCube[4][3];
		myCube[4][3] = myCube[2][2];
		myCube[2][2] = myCube[5][3];
		myCube[5][3] = temp3;
	}
}

void unapplyMove(int moveType)
{
	int temp1 = 0, temp2 = 0, temp3 = 0;

	if(moveType == 1)
	{
		temp1 = myCube[0][0];
		myCube[0][0] = myCube[0][3];
		myCube[0][3] = myCube[0][2];
		myCube[0][2] = myCube[0][1];
		myCube[0][1] = temp1;

		temp2 = myCube[1][2];
		myCube[1][2] = myCube[5][0];
		myCube[5][0] = myCube[3][0];
		myCube[3][0] = myCube[4][2];
		myCube[4][2] = temp2;

		temp3 = myCube[1][3];
		myCube[1][3] = myCube[5][1];
		myCube[5][1] = myCube[3][1];
		myCube[3][1] = myCube[4][3];
		myCube[4][3] = temp3;
	}
	else if(moveType == 2)
	{
		temp1 = myCube[0][0];
		myCube[0][0] = myCube[0][1];
		myCube[0][1] = myCube[0][2];
		myCube[0][2] = myCube[0][3];
		myCube[0][3] = temp1;

		temp2 = myCube[1][2];
		myCube[1][2] = myCube[4][2];
		myCube[4][2] = myCube[3][0];
		myCube[3][0] = myCube[5][0];
		myCube[5][0] = temp2;

		temp3 = myCube[1][3];
		myCube[1][3] = myCube[4][3];
		myCube[4][3] = myCube[3][1];
		myCube[3][1] = myCube[5][1];
		myCube[5][1] = temp3;
	}
	else if(moveType == 3)
	{
		temp1 = myCube[2][0];
		myCube[2][0] = myCube[2][3];
		myCube[2][3] = myCube[2][2];
		myCube[2][2] = myCube[2][1];
		myCube[2][1] = temp1;

		temp2 = myCube[4][0];
		myCube[4][0] = myCube[3][2];
		myCube[3][2] = myCube[5][2];
		myCube[5][2] = myCube[1][0];
		myCube[1][0] = temp2;

		temp3 = myCube[4][1];
		myCube[4][1] = myCube[3][3];
		myCube[3][3] = myCube[5][3];
		myCube[5][3] = myCube[1][1];
		myCube[1][1] = temp3;
	}
	else if(moveType == 4)
	{
		temp1 = myCube[2][0];
		myCube[2][0] = myCube[2][1];
		myCube[2][1] = myCube[2][2];
		myCube[2][2] = myCube[2][3];
		myCube[2][3] = temp1;

		temp2 = myCube[4][0];
		myCube[4][0] = myCube[1][0];
		myCube[1][0] = myCube[5][2];
		myCube[5][2] = myCube[3][2];
		myCube[3][2] = temp2;

		temp3 = myCube[4][1];
		myCube[4][1] = myCube[1][1];
		myCube[1][1] = myCube[5][3];
		myCube[5][3] = myCube[3][3];
		myCube[3][3] = temp3;
	}
	else if(moveType == 5)
	{
		temp1 = myCube[5][0];
		myCube[5][0] = myCube[5][3];
		myCube[5][3] = myCube[5][2];
		myCube[5][2] = myCube[5][1];
		myCube[5][1] = temp1;

		temp2 = myCube[0][0];
		myCube[0][0] = myCube[1][0];
		myCube[1][0] = myCube[2][0];
		myCube[2][0] = myCube[3][0];
		myCube[3][0] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[1][3];
		myCube[1][3] = myCube[2][3];
		myCube[2][3] = myCube[3][3];
		myCube[3][3] = temp3;
	}
	else if(moveType == 6)
	{
		temp1 = myCube[5][0];
		myCube[5][0] = myCube[5][1];
		myCube[5][1] = myCube[5][2];
		myCube[5][2] = myCube[5][3];
		myCube[5][3] = temp1;

		temp2 = myCube[0][0];
		myCube[0][0] = myCube[3][0];
		myCube[3][0] = myCube[2][0];
		myCube[2][0] = myCube[1][0];
		myCube[1][0] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[3][3];
		myCube[3][3] = myCube[2][3];
		myCube[2][3] = myCube[1][3];
		myCube[1][3] = temp3;
	}
	else if(moveType == 7)
	{
		temp1 = myCube[4][0];
		myCube[4][0] = myCube[4][3];
		myCube[4][3] = myCube[4][2];
		myCube[4][2] = myCube[4][1];
		myCube[4][1] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[3][1];
		myCube[3][1] = myCube[2][1];
		myCube[2][1] = myCube[1][1];
		myCube[1][1] = temp2;

		temp3 = myCube[0][2];
		myCube[0][2] = myCube[3][2];
		myCube[3][2] = myCube[2][2];
		myCube[2][2] = myCube[1][2];
		myCube[1][2] = temp3;
	}
	else if(moveType == 8)
	{
		temp1 = myCube[4][0];
		myCube[4][0] = myCube[4][1];
		myCube[4][1] = myCube[4][2];
		myCube[4][2] = myCube[4][3];
		myCube[4][3] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[1][1];
		myCube[1][1] = myCube[2][1];
		myCube[2][1] = myCube[3][1];
		myCube[3][1] = temp2;

		temp3 = myCube[0][2];
		myCube[0][2] = myCube[1][2];
		myCube[1][2] = myCube[2][2];
		myCube[2][2] = myCube[3][2];
		myCube[3][2] = temp3;
	}
	else if(moveType == 9)
	{
		temp1 = myCube[3][0];
		myCube[3][0] = myCube[3][3];
		myCube[3][3] = myCube[3][2];
		myCube[3][2] = myCube[3][1];
		myCube[3][1] = temp1;

		temp2 = myCube[0][2];
		myCube[0][2] = myCube[5][1];
		myCube[5][1] = myCube[2][0];
		myCube[2][0] = myCube[4][1];
		myCube[4][1] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[5][2];
		myCube[5][2] = myCube[2][1];
		myCube[2][1] = myCube[4][2];
		myCube[4][2] = temp3;
	}
	else if(moveType == 10)
	{
		temp1 = myCube[3][0];
		myCube[3][0] = myCube[3][1];
		myCube[3][1] = myCube[3][2];
		myCube[3][2] = myCube[3][3];
		myCube[3][3] = temp1;

		temp2 = myCube[0][2];
		myCube[0][2] = myCube[4][1];
		myCube[4][1] = myCube[2][0];
		myCube[2][0] = myCube[5][1];
		myCube[5][1] = temp2;

		temp3 = myCube[0][3];
		myCube[0][3] = myCube[4][2];
		myCube[4][2] = myCube[2][1];
		myCube[2][1] = myCube[5][2];
		myCube[5][2] = temp3;
	}
	else if(moveType == 11)
	{
		temp1 = myCube[1][0];
		myCube[1][0] = myCube[1][3];
		myCube[1][3] = myCube[1][2];
		myCube[1][2] = myCube[1][1];
		myCube[1][1] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[4][0];
		myCube[4][0] = myCube[2][3];
		myCube[2][3] = myCube[5][0];
		myCube[5][0] = temp2;

		temp3 = myCube[0][0];
		myCube[0][0] = myCube[4][3];
		myCube[4][3] = myCube[2][2];
		myCube[2][2] = myCube[5][3];
		myCube[5][3] = temp3;
	}
	else if(moveType == 12)
	{
		temp1 = myCube[1][0];
		myCube[1][0] = myCube[1][1];
		myCube[1][1] = myCube[1][2];
		myCube[1][2] = myCube[1][3];
		myCube[1][3] = temp1;

		temp2 = myCube[0][1];
		myCube[0][1] = myCube[5][0];
		myCube[5][0] = myCube[2][3];
		myCube[2][3] = myCube[4][0];
		myCube[4][0] = temp2;

		temp3 = myCube[0][0];
		myCube[0][0] = myCube[5][3];
		myCube[5][3] = myCube[2][2];
		myCube[2][2] = myCube[4][3];
		myCube[4][3] = temp3;
	}
}

// ID-DFS to solve the cube
bool solveCube(int depth, int MaxDepth)
{
    if (isSolved())
    {
        return true;
    }
    if (depth >= MaxDepth)
    {
        return false;
    }

    for (int move = 1; move <= 12; move++)
    {
        moves[depth] = move;  // Add the move to the array
    		counter++;

    		applyMove(move);
        if (solveCube(depth + 1, MaxDepth)) return true;
        unapplyMove(move);
    }
    return false;
}

bool findOptimalSolution()
{
    for (int maxDepth = 1; maxDepth <= 14; maxDepth++)
    {
        if (solveCube(0, maxDepth))
        {
            return true; // Solution found at this depth
        }
    }
    return false; // No solution found within set depth limit
}

void moveCube()
{
	for(int index = 0; index < 14; index++)
	{
		if(moves[index] == 1) U();
		else if(moves[index] == 2) UPrim();
		else if(moves[index] == 3) Dd();
		else if(moves[index] == 4) DPrim();
		else if(moves[index] == 5) R();
		else if(moves[index] == 6) RPrim();
		else if(moves[index] == 7) L();
		else if(moves[index] == 8) LPrim();
		else if(moves[index] == 9) F();
		else if(moves[index] == 10) FPrim();
		else if(moves[index] == 11) B();
		else if(moves[index] == 12) BPrim();
	}
}

task main()
{
	scanCube();

	while(SensorValue[S2] < 1)
	{
		while(SensorValue[S3] < 3)
		{
			if(findOptimalSolution())
			{
				displayString(3,"%e",counter);
				displayString(4, "found solution");
				displayString(5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d",moves[0],moves[1], moves[2], moves[3], moves[4], moves[5], moves[6], moves[7], moves[8], moves[9], moves[10], moves[11], moves[12], moves[13]);
			}
			else displayString(4,"%e",counter);

			time100[T1]=0;
			moveCube();
			float timer = time100[T1]/1000;
			displayString(6,"%s","Time spent:");
			displayString(7,"%f",timer);
		}
	}
}
