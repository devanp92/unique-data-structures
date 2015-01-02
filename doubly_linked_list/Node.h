/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  Simple Node struct
 *
 *        Version:  1.0
 *        Created:  01/01/2015 21:37:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __NODE_H__
#define __NODE_H__
struct node;
typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} node;

#endif
