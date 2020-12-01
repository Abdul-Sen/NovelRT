// Copyright © Matt Jones and Contributors. Licensed under the MIT License (MIT). See LICENCE.md in the repository root for more information.

#include <gtest/gtest.h>
#include <NovelRT.h>
#include <atomic>

using namespace NovelRT;
using namespace NovelRT::Ecs;

TEST(SparseSetTest, InsertDoesNotThrowWhenAddingValidItemToCollection)
{
    SparseSet<Atom, int32_t, AtomHashFunction> testSet;
    EXPECT_NO_THROW(testSet.Insert(Atom(0), 1));
}

TEST(SparseSetTest, RemoveDoesNotThrowWhenRemovingValidItemFromCollection)
{
    SparseSet<Atom, int32_t, AtomHashFunction> testSet;
    ASSERT_NO_THROW(testSet.Insert(Atom(0), 1));
    EXPECT_NO_THROW(testSet.Remove(Atom(0)));
}

TEST(SparseSetTest, InsertInsertsValidItemCorrectly)
{
    SparseSet<Atom, int32_t, AtomHashFunction> testSet;
    ASSERT_NO_THROW(testSet.Insert(Atom(0), 1));
    EXPECT_EQ(testSet[Atom(0)], 1);
}

TEST(SparseSetTest, RemoveUpdatesSetCorrectlyAfterRemovingElement)
{
    SparseSet<Atom, int32_t, AtomHashFunction> testSet;
    ASSERT_NO_THROW(testSet.Insert(Atom(0), 1));
    ASSERT_NO_THROW(testSet.Insert(Atom(1), 1));
    ASSERT_NO_THROW(testSet.Remove(Atom(1)));
    EXPECT_EQ(testSet[Atom(1)], 1);
}

