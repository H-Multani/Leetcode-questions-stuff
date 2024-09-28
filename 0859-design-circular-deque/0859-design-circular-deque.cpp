class MyCircularDeque {
    // stores all the elements
    vector<int> dq;

    // frnt and rear pointers
    // NOTE: frnt ptr goes to the right when adding,
    // and rear ptr goes to the left when adding elements
    int frntptr, rearptr;

    // the maxm size of the allowed for list
    int maxsize;

public:
    MyCircularDeque(int k) {
        // initialize the dq array, 2n+1 elements, all values 0 intitally
        // 0 signifies that no element has been added here
        dq.resize((2 * k) + 1, 0);

        // since maxm k elements need to be filled in dq
        maxsize = k;
        // set both pointers at middle index of list
        frntptr = k, rearptr = k;
    }

    bool insertFront(int value) {
        // chk if list isnt empty, if list empty return false, since cant add
        // any more elements
        if (frntptr - rearptr >= maxsize)
            return false;

        // means list isnt empty, add elements
        // for front, first add the element at the frnt ptr index
        dq[frntptr] = value;
        // then increment the frnt ptr
        frntptr++;
        // now frnt ptr is at posn where the next new element can be added

        // return true since element has been added
        return true;
    }

    bool insertLast(int value) {
        // chk if list isnt empty, if list empty return false, since cant add
        // any more elements
        if (frntptr - rearptr >= maxsize)
            return false;

        // means list isnt empty, add elements
        // for rear, first decrement the rear ptr to get to new posn for element
        rearptr--;
        // then insert the element
        dq[rearptr] = value;
        // now rear ptr is at posn where current new element has just been added

        // return true since element has been added
        return true;
    }

    bool deleteFront() {

        // check if list empty or not
        // if rear ptr ahead of frnt ptr, means list empty, return false
        // or of frnt and rear ptrs at same index, and element value=0, means
        // list is empty, return false, since element cant be deleted
        if (frntptr < rearptr || (frntptr == rearptr && dq[frntptr] == 0)) {
            return false;
        }

        // decrement frnt ptr, to get to the element that need to be deleted
        frntptr--;

        // now we at the element to be deleted, set curr idx value to be 0, to
        // signify that element has been deleted
        dq[frntptr] = 0;
        // now again frnt ptr is at posn where the next new element can be added
        // and one idx ahead of the next front top element

        // return true, to signify that we have deleted the element
        return true;
    }

    bool deleteLast() {
        // check if list empty or not
        // if rear ptr ahead of frnt ptr, means list empty, return false
        // or of frnt and rear ptrs at same index, and element value=0, means
        // list is empty, return false,since element cant be deleted
        if (rearptr > frntptr || (frntptr == rearptr && dq[frntptr] == 0)) {
            return false;
        }

        // now rear ptr is already at the element to be deleted posn

        // set current element to 0 to signify that we have deleted the element
        dq[rearptr] = 0;
        // increment rear ptr, to get to the next top rear element
        rearptr++;

        // now we are at the next top rear element, frm here we can remove
        // another element or add element(since for addn we decrement ptr first
        // then add element)

        // return true since we have deleted the element
        return true;
    }

    int getFront() {
        // chk if front top element exists or not
        // this can be checked by 1-> the list is empty, return -1
        // 2-> frnt and rear at same index and the value at the index is 0, ie
        // front has no values return -1, since list empty
        if (frntptr < rearptr || (frntptr == rearptr && dq[frntptr] == 0))
            return -1;

        // now frnt ptr is always 1 idx ahead of the frnt top element, hence
        // return element at frntptr-1 th index
        // (why 1 step ahead?, when inserting we first add element then
        // increment ptr, thats why)
        return dq[frntptr - 1];
    }

    int getRear() {
        // chk if front top element exists or not
        // this can be checked by 1-> the list is empty, return -1
        // 2-> frnt and rear at same index and the value at the index is 0, ie
        // front has no values return -1, since list empty
        if (frntptr < rearptr || (frntptr == rearptr && dq[frntptr] == 0))
            return -1;

        // now rear ptr is always at the rear top element, hence
        // return element at rearptr th index
        // (why at the idx insted of 1 step ahead?, when inserting we first
        // decrement ptr then add element, thats why)
        return dq[rearptr];
    }

    bool isEmpty() {

        // if frnt ptr on same posn as rear ptr, means dq is empty, return true
        if (frntptr == rearptr)
            return true;

        // we here means dq isnt empty, return false
        return false;
    }

    bool isFull() {
        // if size of dq(the no of elements we have filled)== max allowed
        // size(k), means dq is full, return true
        if (frntptr - rearptr == maxsize)
            return true;

        // we here means dq isnt full yet, return false
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */