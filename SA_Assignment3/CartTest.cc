#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cart.h"
#include "Item.h"
#include "ItemService.h"

// -----------------------------------------------------------------------------
// MockItemService: A mock implementation of the ItemService interface.
// Uses Google Mock to simulate the getPrice() method.
class MockItemService : public ItemService {
public:
    // MOCK_METHOD creates a mock method for getPrice.
    // It takes an Item reference and returns a double representing the price.
    MOCK_METHOD(double, getPrice, (Item& item), (override));
};

// -----------------------------------------------------------------------------
// CartTestFixture: Test fixture for testing the Cart class.
class CartTestFixture : public ::testing::Test {
protected:
    // Instance of Cart to test.
    Cart testCart;

    // Mock object for ItemService, used to provide prices.
    MockItemService mockPriceService;

    // SetUp() is called before each test.
    void SetUp() override {
        std::cout << "SetUp: Preparing the test environment..." << std::endl;

        testCart.setItemService(&mockPriceService);

        // Create test Items:
        // "SDcard": ID "1", quantity: 1 price: 10
        Item itemSDCard("1", "SDcard", 1);
        // "LEDlight": ID "2", quantity: 1 price: 10
        Item itemLEDLight("2", "LEDlight", 1);
        // "DashCam": ID "3", quantity 2 price: 20
        Item itemDashCam("3", "DashCam", 2);

        // Add these Items to a vector.
        std::vector<Item> items = { itemSDCard, itemLEDLight, itemDashCam };

        // Set the items in the Cart.
        testCart.setItems(items);
    }

    // TearDown() is called after each test.
    void TearDown() override {
        std::cout << "TearDown: Cleaning up after the test..." << std::endl;
    }
};

// -----------------------------------------------------------------------------
// Test Case:
// The total is calculated as:
//   1 * 10 (SDcard) + 1 * 10 (LEDlight) + 2 * 20 (DashCam) = 60.
TEST_F(CartTestFixture, TotalAmountShouldBe60) {
    EXPECT_CALL(mockPriceService, getPrice(::testing::_))
        .WillRepeatedly([](Item& item) -> double {
            if (item.getItemId() == "1") {
                return 10.0;  // Price for SDcard.
            } else if (item.getItemId() == "2") {
                return 10.0;  // Price for LEDlight.
            } else if (item.getItemId() == "3") {
                return 20.0;  // Price for DashCam.
            }
            return 0.0;       // Default: unknown item.
        });

    // Call the method to compute the total amount.
    double calculatedTotal = testCart.getCartTotalAmount();
    std::cout << "Calculated Total: " << calculatedTotal << std::endl;
    EXPECT_EQ(calculatedTotal, 60.0);


    // Verify the result matches the expected total (60.0).
    EXPECT_EQ(calculatedTotal, 60.0);
}
