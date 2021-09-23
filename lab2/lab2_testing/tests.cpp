#include <iostream>
#include <gtest/gtest.h>
#include <library.h>

TEST(Constructors_Tests, Constructor_with_one_variable_and_incorrect_radius){
    ASSERT_ANY_THROW(deltoida delt(-12));
}
TEST(Constructors_Tests, Constructor_with_one_variable_and_correct_radius){
    deltoida delt(12345.567);
    ASSERT_DOUBLE_EQ(12345.567, delt.get());
}
TEST(Constructors_Tests, Constructor_without_variable){
    deltoida delt;
    ASSERT_DOUBLE_EQ(0, delt.get());
}
TEST(Constructors_Tests, Constructor_with_one_variable_and_correct_radius_equal_0){
    deltoida delt(0);
    ASSERT_DOUBLE_EQ(0, delt.get());
}
TEST(Constructors_Tests,Copy_constructor){
    deltoida delt1(rand());
    deltoida delt2(delt1);
    ASSERT_DOUBLE_EQ(delt2.get(),delt1.get());
}


TEST(Methods_Tests, get__1){
    deltoida delt(43293.6);
    ASSERT_DOUBLE_EQ(43293.6,delt.get());
}
TEST(Methods_Tests, get__2){
    deltoida delt(0);
    ASSERT_DOUBLE_EQ(0,delt.get());
}



TEST(Methods_Tests, set__1){
    deltoida delt;
    ASSERT_ANY_THROW(delt.set_radius(-154));
}
TEST(Methods_Tests, set__2){
    deltoida delt;
    ASSERT_NO_THROW(delt.set_radius(45));
}
TEST(Methods_Tests, set__3){
    deltoida delt;
    ASSERT_DOUBLE_EQ(567,delt.set_radius(567));
}
TEST(Methods_Tests, set__4){
    deltoida delt(4);
    ASSERT_DOUBLE_EQ(0,delt.set_radius(0));
}


TEST(Methods_Tests,the_length_of_the_intersection){
    int a=abs(rand());
    deltoida delt(a);
    ASSERT_DOUBLE_EQ(4*(b*a)/3,delt.the_length_of_the_intersection());
}

TEST(Methods_Tests,the_length_of_the_intersection_with_radius_0){
    deltoida delt;
    ASSERT_DOUBLE_EQ(0,delt.the_length_of_the_intersection());
}


TEST(Methods_Tests,length_of_the_curve){
    int a=abs(rand());
    deltoida delt(a);
    ASSERT_DOUBLE_EQ(16*(b*a)/3,delt.length_of_the_curve());
}


TEST(Methods_Tests,length_of_the_curve_with_radius_0){
    deltoida delt;
    ASSERT_DOUBLE_EQ(0,delt.length_of_the_curve());
}


TEST(Methods_Tests, x_and_y_dependence_from_t){
    deltoida delt(rand());
    double t=rand();
    double* test=delt.x_and_y_dependence_from_t(t);
    ASSERT_DOUBLE_EQ((b-1) * delt.get() * cos(t) + delt.get() * cos((b-1) * t),test[0]);
    ASSERT_DOUBLE_EQ((b-1) * delt.get() * sin(t) - delt.get() * sin((b-1) * t),test[1]);
    delete[] test;
}


TEST(Methods_Tests,area){
    int a=abs(rand());
    deltoida delt(a);
    ASSERT_DOUBLE_EQ(2*pi*(b*a)*(b*a)/9,delt.area());
}
TEST(Methods_Tests,area_with_radius_0){
    deltoida delt;
    ASSERT_DOUBLE_EQ(0,delt.area());
}


TEST(Methods_Tests,text_view_of_equation){
    deltoida delt;
    ASSERT_STREQ("(x^2+y^2)^2+18(x^2+y^2)=8x^3+24xy^2+27",delt.text_view_of_equation());
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}