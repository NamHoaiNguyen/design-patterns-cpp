#ifndef shipping_service
#define shipping_service

template<typename T>
class ShippingService {
public:
    ShippingService() = default;
    decltype(auto) free_shipping();
    decltype(auto) standard_shipping();
    decltype(auto) express_shipping();
};

template<typename T>
decltype(auto) ShippingService<T>::free_shipping()
{
    std::cout << "Free Shipping" << std::endl;
}

template<typename T>
decltype(auto) ShippingService<T>::standard_shipping()
{
    std::cout << "Standard Shipping " << std::endl;
}

template<typename T>
decltype(auto) ShippingService<T>::express_shipping()
{
    std::cout << "Express Shipping" << std::endl;
}

#endif