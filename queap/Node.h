/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  Two Four Tree Node struct
 *
 *        Version:  1.0
 *        Created:  01/01/2015 21:37:21
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
    int keys[3];
    struct node* children[4];
} node;

#endif
