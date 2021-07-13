#ifndef shop_facade
#define shop_facade

#include <iostream>
#include <memory>
#include <mutex>

#include "AccountService.h"
#include "EmailService.h"
#include "PaymentService.h"
#include "ShippingService.h"
#include "SmsService.h"

template<typename Acc, typename Email, typename Payment, typename Shipping, typename Sms>
class ShopFacade {
private:
    static std::mutex mutex_;
    static std::shared_ptr<ShopFacade<Acc, Email, Payment, Shipping, Sms>> mInstancePtr;
    AccountService<Acc> accountService;
    EmailService<Email> emailService;
    PaymentService<Payment> paymentService;
    ShippingService<Shipping> shippingService;
    SmsService<Sms> smsService;

    ShopFacade();
public:
    static decltype(auto) get_instance();
    decltype(auto) buyProductByCashWithFreeShipping(Email&& email);
    ShopFacade(const ShopFacade&) = delete;
    ShopFacade &operator=(const ShopFacade&) = delete;
    ShopFacade(ShopFacade&&) = delete;
    ShopFacade &operator=(ShopFacade&&) = delete;
};

template<typename Acc, typename Email, typename Payment, typename Shipping, typename Sms>
ShopFacade<Acc, Email, Payment, Shipping, Sms>::ShopFacade()
{

}

template<typename Acc, typename Email, typename Payment, typename Shipping, typename Sms>
decltype(auto) ShopFacade<Acc, Email, Payment, Shipping, Sms>::get_instance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (mInstancePtr == nullptr) 
        mInstancePtr = std::make_shared<ShopFacade<Acc, Email, Payment, Shipping, Sms>>();
    return mInstancePtr;
}

template<typename Acc, typename Email, typename Payment, typename Shipping, typename Sms>
decltype(auto) ShopFacade<Acc, Email, Payment, Shipping, Sms>::buyProductByCashWithFreeShipping(Email&& email)
{
    accountService.get_account(std::forward<Email>(email));
    paymentService.payment_cash();
    shippingService.free_shipping();
    emailService.send_email();
    std::cout << "Done " << std::endl; 
}

#endif