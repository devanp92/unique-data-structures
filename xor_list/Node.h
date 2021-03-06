/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  XOR List Node struct
 *
 *        Version:  1.0
 *        Created:  01/15/2015 21:37:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *
 * =====================================================================================
 */

#ifndef __NODE_H__
#define __NODE_H__

struct node;
typedef struct node {
    int val;
    struct node* next;
} node;

#endif
