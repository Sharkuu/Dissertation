//
// Created by olav on 14.11.2016.
//

#ifndef DISSERTATION_TEST_H
#define DISSERTATION_TEST_H


int test(){
return RUN_ALL_TESTS();}

TEST(test,one){
    ASSERT_EQ(1,0);
}

TEST(test,two){
    ASSERT_EQ(1,1);
}
#endif //DISSERTATION_TEST_H
