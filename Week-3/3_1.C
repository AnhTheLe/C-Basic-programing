#include <stdio.h>
#include <stdlib.h>
#include <string>
struct address {
	char name[32];
	char phone[11];
	char email[64];
	address * link;
};
typedef address * node;
node createNode(char * name, char * phone, char * email)
{
	node temp;
	temp = (node)malloc(sizeof(struct address));
	temp->link = NULL;
	strcpy(temp->name, name);
	strcpy(temp->phone, phone);
	strcpy(temp->email, email);
	return temp;
}
// Them vao dau day
node AddHead(node root, node newItem)
{
	if(root == NULL)
	{
		root = newItem;
	}
	else
	{
		newItem->link = root;
		root = newItem;
	}
	
	return root;
}
// Them phan tu vao cuoi day
node pushEnd(node root, node newItem)
{
	if(root == NULL)
	{
		root = newItem;
	}
	else
	{
		node tmp = root;
		while(tmp->link != NULL)
		{
			tmp = tmp->link;
		}
		
		tmp->link = newItem;
	}
	return root;
}

node addAt(node root, node newItem, int index)
{
	if(root == NULL || index == 0)
	{
		root = AddHead(root, newItem);
	}
	else
	{
		int k = 1;
		node p = root;
		while(p != NULL && k != index)
		{
			p = p->link;
			k++;
		}
		
		if(k == index)
		{
			newItem->link = p->link;
			p->link = newItem;
		}
		else
		{
			printf("Khong tim thay vi tri can them");
		}
	}
	
	return root;
}

void readNode(node root) 
{
	node tmp = root;
	int i = 1;
	while(1)
	{
		if(tmp == NULL)
		{
			break;
		}
		printf("Thong tin nguoi thu: %d\n", i);
		printf("\tHo ten: %s\n", tmp->name);
		printf("\tPhone: %s\n", tmp->phone);
		printf("\tEmail: %s\n", tmp->email);
		tmp = tmp->link;
		i++;
		if(i > 10000) 
			break;
	}
}
node removeHead(node root) 
{
	if(root == NULL)
	{
		printf("Danh sach trong, khong the xoa");
	}
	else
	{
		root = root->link;
	}
	
	return root;
}
node removeItem(node root, int index)
{
	if(root->link == NULL || root == NULL || index == 0)
	{
		root = removeHead(root);
	}
	else
	{
		int k = 1;
		node tmp = root;
		while(tmp->link->link != NULL && k != index)
		{
			tmp = tmp->link;
			k++;
		}
		
		if(k != index)
		{
			printf("Phan tu nay khong ton tai");
		}
		else
		{
			tmp->link = tmp->link->link;
		}
	}
	
	return root;
}

int main() 
{
	node info_1 = createNode("Doanh0", "0123456789", "dfsdf@gmail.com");
	node info_2 = createNode("Doanh1", "0123456989", "adad@gmail.com");
	node info_3 = createNode("Doanh2", "123444445", "zz@gmail.com");
	node info_4 = createNode("Doanh3", "113", "asas@gmail.com");
	node info_5 = createNode("Doanh5", "0123456789", "12312asda@gmail.com");
	info_1 = pushEnd(info_1, info_2);
	info_1 = pushEnd(info_1, info_3);
	info_1 = pushEnd(info_1, info_4);
	info_1 = addAt(info_1, info_5, 4);
	printf("Sau khi them\n");
	readNode(info_1);
}