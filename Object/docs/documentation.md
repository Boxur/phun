<a id="Object_library"></a>
# Object library

All classes are defined within the `phun` namespace.

<a id="ObjectBase"></a>
# ObjectBase

Class only to store many different types of class [Object\<T\>](#Object) in a single std::vector

**Children**:

- [Object\<T\>](#Object)

**Friends**:

- [ObjectManager](#ObjectManager)

<a id="ObjectBase.public"></a>
## public:

<a id="ObjectBase.Constructor"></a>
#### Constructor

```c++
ObjectBase()
```

Just the basic constructor.

Sets the id\_ to -1 as it's not yet assigned

<a id="ObjectBase.protected"></a>
## protected:

<a id="ObjectBase.id_"></a>
#### id\_

```c++
size_t id_
```

Id of the object in the [ObjectManager](#ObjectManager) class.

<a id="Object"></a>
# Object\<T\>

Automatic memory management class.

**Parents**:

- [ObjectBase](#ObjectBase)

<a id="Object.public"></a>
## public:

<a id="Object.DefaultConstructor"></a>
#### Default Constructor

```c++
Object() = delete
```

The default constructor is deleted to prevent creating an object without a value.

<a id="Object.Constructor"></a>
#### Constructor

```c++
Object(T value)
```

Just the basic constructor.

Creates the object and sets its value.
Registers the object within the [ObjectManager](#ObjectManager).

**Arguments**:

- `value` - the value to assign to the object.

<a id="Object.CopyConstructor"></a>
#### Copy Constructor

```c++
Object(const Object& other)
```

Constructor for instant assignment after creation.

Reassigns the values by reference to the other class
and handles any automatic memory management that happens as a result of it.

<a id="Object.Destructor"></a>
#### Destructor

```c++
~Object()
```

Object's destructor.

Handles automatic memory management that is needed when destroying the object.

<a id="Object.operator="></a>
#### operator=

```c++
Object<T>& operator=(const Object<T>& other)
```

Reassignment operator overload.

Functionally the same as the [Copy Constructor](#Object.CopyConstructor).

<a id="Object.operator*"></a>
#### operator*

```c++
T& operator*()
```

Gets the object value.

From the [ObjectManager](#ObjectManager) class takes the value
in order for it to be accessed by the user.

**Returns**:

Reference to the value stored by the class.


<a id="Object.operator->"></a>
#### operator->

```c++
T* operator->()
```

Operator for accessing data of stored class.

<a id="Object.Value"></a>
#### Value

```c++
T& Value()
```

The same as the [operator*](#Object.operator*) method.

<a id="Object.private"></a>
## private:

<a id="Object.IncreaseCounter_"></a>
#### IncreaseCounter\_

```c++
void IncreaseCounter_()
```

Increase the reference counter.

Increases the reference counter for automatic memory management.

<a id="Object.DecreaseCounter_"></a>
#### DecreaseCounter\_

```c++
void DecreaseCounter_()
```

Decrease the reference counter.

Decreases the reference counter for automatic memory management
and checks if the object is still being used.

<a id="Object.Release_"></a>
#### Release\_

```c++
void Release_()
```

Releases all data stored by the class.

Unregisters object from the [ObjectManager](#ObjectManager)
and frees the id pointer.

<a id="Object.protected"></a>
## protected:

<a id="Object.refCount_"></a>
#### refCount\_

```c++
size_t* refCount_
```

Reference counter for automatic memory management.

Stored as a pointer to allow for multiple objects to point to the same counter in case of reassignment.

<a id="ObjectManager"></a>
# ObjectManager

Class that works with the [Object](#Object) class in order to allow for automatic memory management.
Stores the data separately from all other class data to allow for cache optimization.

**Friends**:

- [Object\<T\>](#Object)

<a id="ObjectManager.public"></a>
## public:

<a id ="ObjectManager.instance"></a>
#### instance

```c++
static ObjectManager& instance()
```

Allows access to a single instance of the class that handles all memory management.

The instance is stored as a static variable inside of the method. This allows for a single instance to exist
while nothing is declared globally.

**Returns**:

A reference to the instance.

<a id="ObjectManager.private"></a>
## private:

<a id="ObjectManager.Constructor"></a>
#### Constructor

```c++
ObjectManager()
```

Just the basic constructor.

The constructor is private to prevent creating multiple instances of the class.

<a id="ObjectManager.CopyConstructor"></a>
#### Copy Constructor

```c++
ObjectManager(const ObjectManager&) = delete
```

The copy constructor is deleted to prevent copying the instance of the class.

<a id="ObjectManager.operator="></a>
#### operator=

```c++
ObjectManager& operator=(const ObjectManager&) = delete
```

The assignment operator is deleted to prevent copying the instance of the class.

<a id="ObjectManager.RegisterObject"></a>
#### RegisterObject

```c++
void RegisterObject(ObjectBase* obj,std::any value)
```

Register a new object to be automatically managed

Registers the object to be automatically managed by the class.

**Arguments**:

- `obj` - the object to be registered.
- `value` - the value to be stored for the object.

<a id="ObjectManager.UnregisterObject"></a>
#### UnregisterObject

```c++
void UnregisterObject(ObjectBase& obj)
```

Unregister an object from being automatically managed.

Unregisters the object from being automatically managed by the class.

**Arguments**:

- `obj` - the object to be unregistered.

<a id="ObjectManager.GetValue"></a>
#### GetValue

```c++
std::any& GetValue(ObjectBase& obj)
```

Gets the value stored for the object in order for it to be accessed by the user.

**Arguments**:

- `obj` - the object to get the value for.

**Returns**:
A reference to the value stored for the object.

<a id="ObjectManager.mutex_"></a>
#### mutex\_

```c++
std::mutex mutex_
```

Mutex for thread safety when accessing the data.

<a id="ObjectManager.objectIndexes_"></a>
#### objectIndexes\_

```c++
std::vector<size_t>	objectIndexes_
```

Vector of all object ids that are currently being managed.

At each index is stored another index 
that points to the location of the value for the object in the
[ids\_](#ObjectManager.ids_),
[objects\_](#ObjectManager.objects_) and
[values\_](#ObjectManager.values_)
vectors.

<a id="ObjectManager.ids_"></a>
#### ids\_

```c++
std::vector<size_t>	ids_
```
Vector of all object ids that are currently being managed.

Used when deleting an object to update the [objectIndexes\_](#objectIndexes_) so they are still accurate.

<a id="ObjectManager.objects_"></a>
#### objects\_

```c++
std::vector<ObjectBase*> objects_
```

Vector of all objects that are currently being managed.

At each index is stored a pointer to the object that is being managed.

<a id="ObjectManager.values_"></a>
#### values\_

```c++
std::vector<std::any> values_
```

Vector of all values that are currently being managed.

At each index is stored the value for the object that is being managed.
They are stored separately from the objects to allow for cache optimization when accessing the values.