#ifndef __PRODUCT__
#define __PRODUCT__

#include <ArduinoSTL.h>

/**
 * @brief An interface representing the concept of Product, 
 * which can be consumed by the smart coffee machine.
 */
class Product {

public:
    /**
     * @brief Consume a unit of this product. 
     */
    virtual void consume() = 0;

    /**
     * @brief Gets the remaining amount of this product.
     * @return int the units of product left.
     */
    virtual int getLeftQuantity() = 0;
    
    /**
     * @brief Returns if this product is available or not. 
     * @return true if this product is available, false otherwise. 
     */
    virtual bool isAvailable() = 0;

    /**
     * @brief Returns the name of this product. 
     * @return String the string representation of this product.
     */
    virtual String toString() = 0;

};

#endif