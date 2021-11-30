# Singleton
It is a design pattern which only allows a user to get one object from a class.
In order to disable creating another object the constructor shall be designed as protected/private

## protected
It allows a derived class to create its object

## private
It doesn't allow to create an object

## static method to "new" an object
It is allowed to call the static function to create an object.
It checkes if the pointer pt is nullptr which means an object is not created yet.
Create the object only when the pt is a nullptr.

For multi-threads:
Considering the efficiency of checking pointer, we should put the lock under the check.
Then check the condition again and create a new object.

## static pointer
The pointer indicates if an object is already created. It points to an object.


