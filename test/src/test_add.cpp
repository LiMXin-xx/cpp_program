//
// Created by LiMXin-PC on 2023/4/1.
//

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : xxx.c
  * @brief          : xxx program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021.
  * All rights reserved.
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/*** Includes ------------------------------------------------------------------*/

/** Private includes ----------------------------------------------------------*/
/** USER CODE BEGIN Includes */
#include "gtest/gtest.h"
#include "bsp/add.h"
/** USER CODE END Includes */

/*** Private typedef -----------------------------------------------------------*/
/** USER CODE BEGIN PTD */

/** USER CODE END PTD */

/*** Private define ------------------------------------------------------------*/
/** USER CODE BEGIN PD */

/** USER CODE END PD */

/*** Private macro -------------------------------------------------------------*/
/** USER CODE BEGIN PM */

/** USER CODE END PM */

/*** Private variables ---------------------------------------------------------*/
/** USER CODE BEGIN PV */

/** USER CODE END PV */

/*** Private function prototypes -----------------------------------------------*/
/** USER CODE BEGIN PFP */
TEST(TestAddInt, test_add_int_1) {
    int res = add_int(10, 24);
    EXPECT_EQ(res, 34);
}
/** USER CODE END PFP */

/*** Private user code ---------------------------------------------------------*/
/** USER CODE BEGIN 0 */

/** USER CODE END 0 */
